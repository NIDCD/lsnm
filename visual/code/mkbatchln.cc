/*rev. 8/98
mkbatchln.cc for left side only, takes random noise input from lgn.
Strictly speaking, left brain input should be GGN.  But LGN and
GGN have identical structures, so this amounts to just a name change.
Additonally, the form input files are labeled for LGN. If we want
to give form input to left brain, it is more convenient to just make
LGN the input. To be conssitent, we just hook left brain to LGN
whenever we are running the left brain by itself.

lgns_in: the number of "on" blocks in the left brain's lgns input.  
lgnseed: The code mkinput  will use this number to randomly select which 
          block is turned on.  If seed = 0, system clock is the seed


attention level parameters are:
leftlo-- for right brain during intertrial period
lefthi steps thru "start" to "end" at an increment of "increment

The attention levels are entered as integers.
e.g. if we want attention level of 0.05, we enter 5.
This input will be converted to the proper unit in the code
We want integer entries because when we generate directory for a
subject with attention level 0.05, we will name that directory b05.
It is necessary to keep the directory names to be of the same length
so we can use petmanip.m later for data manipulation

"BASE" below specifies which  directory (hence which computer) we are on

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define maxline 80
#define maxstring 15

void itoa(int p, char sp[]);

int main()
{
  FILE *infile, *outfile, *appfile;
  float attn,leftlo;
  int nsubj,cleanup,num,k,m,attni,start,end,increment, lgns_in, lgnseed;
  char sp[3],bin[maxline],whereto[maxline],netgen[maxline];
  char Infile[maxline],temp[maxstring];

  const char *BASE= getenv("LSNM");

  strcpy(bin,BASE);
  strcat(bin,"bin/");
  strcpy(netgen,bin);
  strcpy(Infile,BASE);
  strcat(Infile,"code/mkbatchln.in");
  if( (infile = fopen(Infile, "r")) == NULL)
    {
      printf("can't open %s\n", Infile);
      exit(0);
    }

  outfile = fopen("batchln","w");
  appfile = fopen("appln","w");

  fprintf(appfile,"#include %sweights/left/leftlist.txts\n",BASE);
  fprintf(appfile,"#include %sinputs/pethil.rs\n",BASE);
  fclose(appfile);

  fscanf(infile,"%s %s",temp, whereto);
  fscanf(infile,"%d %d %d %d %d %f %d %d %d",
     &nsubj,&cleanup,&m,&lgns_in,&lgnseed,&leftlo,&start,&end,&increment);

  if(cleanup == 0 && nsubj > 1)
    {
      printf("If you are running multi-subjects, you shouldn't set the cleanup to 0,TSK! TSK!\n");
    }

  strcat(netgen,temp);
  if(lgnseed == 0)
    lgnseed = time(NULL);

  if(increment == 0)
    num = 1;
  else
    num = (end - start)/increment + 1;

  leftlo /= 100.0;

  /* start*/

  fprintf(outfile,"#\n#\n#\n");
  fprintf(outfile,"cd %s\n",BASE);
  fprintf(outfile,"cd weights/right\n");
  fprintf(outfile,"%s ectlectl.ws\n",netgen);
  fprintf(outfile,"%s ectlictl.ws\n",netgen);
  fprintf(outfile,"%s ictlectl.ws\n",netgen);
  fprintf(outfile,"cd %s\n",BASE);
  fprintf(outfile,"mkdir noisy\n");

/*lo attention on left do not change among subjects*/
  fprintf(outfile,"cd sfiles\n");
  fprintf(outfile,"%smkattn loattn_l.s %4.2f\n",bin,leftlo);
  fprintf(outfile,"cd %s\n",BASE);
  /*make "m" noisy input files, the .inp file index starts at 1*/
  fprintf(outfile,"cd inputs\n");
  for(k = 1; k <= m; k++)
    {
      fprintf(outfile,"%smkinput r %d %d\n",bin,lgns_in, lgnseed);
      fprintf(outfile,"mv lgns.inp input%d.inp\n",k);
      lgnseed++;
    }

  fprintf(outfile,"cd %s\n",BASE);

  fprintf(outfile,"rm pethi.s\n");
  fprintf(outfile,"cat weights/left/lefto.s code/appln > pethi.s\n");
  fprintf(outfile,"rm code/appln\nrm code/batchln\n");

  for(k = 0; k < num; k++)
    {
      attni =start + k* increment;
      attn = (float)attni/100.0;
      itoa(attni,sp);

      fprintf(outfile,"#\n#\n");

      if(nsubj > 0)
	{
	  fprintf(outfile,"cd %sweights/left\n",BASE);
	  fprintf(outfile,"for file in *.ws ; do\n");
	  fprintf(outfile,"  %s $file\n  done\n",netgen);
	  if(nsubj == 1)
	    nsubj--;
	}
      fprintf(outfile,"cd %ssfiles\n",BASE);
      fprintf(outfile,"%smkattn hiattn_l.s %4.2f\n",bin,attn);
      fprintf(outfile,"cd %s\n",BASE);
      fprintf(outfile,"%ssim1 pethi\n",bin);
      fprintf(outfile,"gzip *.out\ncd noisy\nmkdir b%s\n",sp);
      fprintf(outfile,"cd %s\n",BASE);

      fprintf(outfile,"mv spec_pet.m noisy/b%s/\nmv *.out.gz noisy/b%s/\n",sp,sp);
    }
  if(cleanup != 0)
    {
      fprintf(outfile,"\nrm weights/right/*.w\n");
      fprintf(outfile,"rm weights/left/*.w\n");
    }
  fprintf(outfile,"cd inputs\n");
  for(k = 1; k <= m; k++)
    {
      fprintf(outfile,"cp input%d1.inp input%d.inp\n",k,k);
    }
  fprintf(outfile,"cd %s\n",BASE);
  fprintf(outfile,"\nrm sfiles/*attn*.s\n");
  fprintf(outfile,"mv noisy %s/nL\n",whereto);

  fclose(infile);
  fclose(outfile);

}

