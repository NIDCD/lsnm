#if on alw using c++ code
CC = g++
#LIB0 =  -lstdc++ -lm

#if on alw using c code, which are netgen and sim codes
#CC = gcc
#LIB0 = -lgcc -lc -lm

# compile on churn, skip the library, let the compiler find it
#setenv LD_LIBRARY_PATH /usr/local/lib if must use g++ on churn
# it is recommended to use CC (SGI's c++) 
#CC = CC
LIB0 = -lm -lc
BASE = ../bin/

.KEEP_STATE:

time_axis: time_axis.cc 
	$(CC) time_axis.cc  -o  $(BASE)time_axis $(LIB0)

readv4wt: readv4wt.cc 
	$(CC) readv4wt.cc  -o $(BASE)readv4wt $(LIB0)

makews: makews.o namechange.o dows.o
	$(CC) makews.o namechange.o dows.o  -o $(BASE)makews $(LIB0)
makews.o:	
	$(CC) -c 	makews.cc
namechange.o:	
	$(CC) -c 	namechange.cc
dows.o:	
	$(CC) -c 	dows.cc

mklist: mklist.o namechange.o 
	$(CC) mklist.o namechange.o   -o $(BASE)mklist $(LIB0)
mklist.o:	
	$(CC) -c 	mklist.cc

mkdots: mkdots.o namechange.o 
	$(CC) mkdots.o namechange.o   -o $(BASE)mkdots $(LIB0)
mkdots.o:	
	$(CC) -c 	mkdots.cc

mketoe: mketoe.o namechange.o 
	$(CC) mketoe.o namechange.o -o mketoe $(LIB0)
mketoe.o:	
	$(CC) -c 	mketoe.cc

crosswt: crosswt.cc
	$(CC) crosswt.cc  -o $(BASE)crosswt $(LIB0)

crosswt_i: crosswt_i.cc 
	$(CC) crosswt_i.cc  -o $(BASE)crosswt_i $(LIB0)

crossws: crossws.cc 
	$(CC) crossws.cc  -o $(BASE)crossws $(LIB0)

genw: genw.cc 
	$(CC) genw.cc  -o $(BASE)genw $(LIB0)

altgenw: altgenw.cc
	$(CC) altgenw.cc -o $(BASE)altgenw $(LIBO)

altgenw_L: altgenw_L.cc
	$(CC) altgenw_L.cc -o $(BASE)altgenw_L $(LIBO)

change: change.cc 
	$(CC) change.cc  -o $(BASE)change $(LIB0)

mkcatout: mkcatout.cc
	$(CC) mkcatout.cc -o $(BASE)mkcatout $(LIBO)

mkggns: mkggns.cc 
	$(CC) mkggns.cc -o $(BASE)mkggns $(LIB0)  

mkinput: mkinput.cc 
	$(CC) mkinput.cc -o $(BASE)mkinput $(LIB0)  

mklgns: mklgns.cc 
	$(CC) mklgns.cc -o $(BASE)mklgns $(LIB0)  

mkattn: mkattn.cc
	$(CC) mkattn.cc -o $(BASE)mkattn $(LIB0)
  
itoa.o:	itoa.cc
	$(CC) -c itoa.cc

mkbatch: mkbatch.cc itoa.o
	$(CC) mkbatch.cc itoa.o -o $(BASE)mkbatch $(LIB0)  

mkbatchw: mkbatchw.cc  itoa.o 
	$(CC) mkbatchw.cc itoa.o -o $(BASE)mkbatchw $(LIB0)  

mkbatchb: mkbatchb.cc itoa.o
	$(CC) mkbatchb.cc itoa.o -o $(BASE)mkbatchb $(LIBO)

mkbatchrlcomb: mkbatchrlcomb.cc itoa.o
	$(CC) mkbatchrlcomb.cc itoa.o -o $(BASE)mkbatchrlcomb $(LIBO)

fmri: fMRI.cc  itoa.o 
	$(CC) fMRI.cc itoa.o -o $(BASE)fmri $(LIB0)  

mkbatchn: mkbatchn.cc  itoa.o
	$(CC) mkbatchn.cc itoa.o -o $(BASE)mkbatchn $(LIB0)  

mkbatchnw: mkbatchnw.cc  itoa.o
	$(CC) mkbatchnw.cc itoa.o -o $(BASE)mkbatchnw $(LIB0)  

mkbatchd: mkbatchd.cc  itoa.o
	$(CC) mkbatchd.cc itoa.o -o $(BASE)mkbatchd $(LIB0)  

mkbatchdw: mkbatchdw.cc  itoa.o
	$(CC) mkbatchdw.cc itoa.o -o $(BASE)mkbatchdw $(LIB0)  

mkbatchr: mkbatchr.cc  itoa.o 
	$(CC) mkbatchr.cc itoa.o -o $(BASE)mkbatchr $(LIB0)  

mkbatchrw: mkbatchrw.cc  itoa.o 
	$(CC) mkbatchrw.cc itoa.o -o $(BASE)mkbatchrw $(LIB0)  

mkbatchrn: mkbatchrn.cc  itoa.o 
	$(CC) mkbatchrn.cc itoa.o -o $(BASE)mkbatchrn $(LIB0)  

r2batch: r2batch.cc  itoa.o 
	$(CC)r2batch.cc itoa.o -o $(BASE)r2batch $(LIB0)  

mkbatchl: mkbatchl.cc itoa.o 
	$(CC) mkbatchl.cc itoa.o -o $(BASE)mkbatchl $(LIB0)  

mkbatchln: mkbatchln.cc itoa.o 
	$(CC) mkbatchln.cc itoa.o -o $(BASE)mkbatchln $(LIB0)  

alz: alz.cc 
	$(CC) alz.cc -o $(BASE)alz $(LIB0) 
 
alzbatchr: alzbatchr.cc itoa.o 
	$(CC) alzbatchr.cc itoa.o -o $(BASE)alzbatchr $(LIB0)  

addwt: addwt.cc 
	$(CC) addwt.cc -o $(BASE)addwt $(LIB0) 
 

