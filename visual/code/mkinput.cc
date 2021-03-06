/* mkinput.cc  rev. 8/98
   make  a random input pattern for left or right brain by selecting
   "n" random units on. the rest is off.  If we want right
   brain input, we enter r at the command line.  If we
   want left brain input we enter l at the command line. The value of 
   "n", is command line input also. e.g if we want 5 elements on
   in lgns, we enter the following at the prompt:
   mkinput r 5
   0.92 is default magnitude for each on element.  If we want a different
   value, change the definition mag below.

   If in addition, we want to enter a seed, say 679
   >mkinput r 5  679
   If no seed is entered, system clock will be used as seed

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define mag 0.92
#define length 9

int main(int argc, char **argv)
{
  FILE *outfile;
  int i,j,k,p,num_on, square;
 
  long seed = time(NULL);
  short **Bmap;

  square = length*length;

  Bmap = new (short (*[length]));
  for(k = 0; k <length ; k++)
    {
      Bmap[k] = new (short [length]);

      for(i = 0; i < length; i++)
	{
	  Bmap[k][i] = 0;
	}
    }

  if(argv[1][0] == 'r' || argv[1][0] == 'R')
    {
      outfile = fopen("lgns.inp","w");
      fprintf(outfile,
         "set  (LGNs,  %d)        %% Turn on LGN,  the Input\n\n",square);  
    }
  else if(argv[1][0] == 'l' || argv[1][0] == 'L')
    {
      outfile = fopen("ggns.inp","w");
      fprintf(outfile,
        "set  (GGNs,  %d)        %% Turn on GGN,  the Input\n\n",square);  
    }
  else
    {
      printf("you need to enter l for left, r for right\n");
      exit(0);
    }
  
  num_on = atoi(argv[2]);
  if(num_on > square)
    {
      printf("number of elements turned on > input size of %d\n",square);
      exit(0);
    }

  if (argv[3] != NULL)
    {
      if(argv[3][0] != '0')
	seed = atoi(argv[3]);
    }

  srand48(seed);


  fprintf(outfile,"{\nNode activation  {ALL 0.0 }\n\nNode activation  {\n");

  k = 0;
  while( k < num_on)
    {
      p = (int)(drand48()*(square - 1));
      i = p/length;
      j = p - i*length;

      /*the output matrix index starts at 1, so we need to add 1*/
      if(Bmap[i][j] == 0)
	{
	  fprintf(outfile,"([%d,%d]   %g) ",i+1,j+1,mag);
	  Bmap[i][j] = 1;
	  k++;
	  fprintf(outfile,"\n");
	}
    }
  fprintf(outfile,"}\n");
  for(k=0; k<length; k++)
    delete [] Bmap[k];
  delete Bmap;
  fclose(outfile);
}













