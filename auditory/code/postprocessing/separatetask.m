% separatetask.m -- July 2003
%
% FORMAT:  separatetask
%
% This program loads task.mat and allactivity.mat in order to separate the
% the form-task blocks and the control blocks.  The separated data is saved in
% a .mat file called sepsynact.mat containing matrices 'tasksynact' and 
% 'ctrlsynact'.
%
% This program also creates two new files containing timing data (T, Tblock,
% nb, etc...) like task.mat.  They are called septask.mat and sepctrl.mat.
%
% Additionally, this program calculates the means for each block, found in
% 'taskmeans' and 'ctrlmeans', as well as total means for all tasks or all
% controls.
%
% Written 07/30/03 by Brent Warner
%
%
% Edited 03/19/2014 by Pearce Decker
%
% Rounded blocksize to eliminate a warning.
%
% Note that all this code really does is split the allactivity matrix so 
% that the first half (rows) of each block goes into tasksynact and the 
% second half goes into ctrlsynact.

load allactivity;

tasksynact = [];
ctrlsynact = [];
blocksize = round(Tblock*20);

for i=1:(nb/2)
   tasksynact = [tasksynact;allsynact(((2*i-2)*blocksize+1):((2*i-1)*blocksize),:)];
   taskmeans(i,:) = mean(allsynact(((2*i-2)*blocksize+1):((2*i-1)*blocksize),:));
   ctrlsynact = [ctrlsynact;allsynact(((2*i-1)*blocksize+1):((2*i)*blocksize),:)];
   ctrlmeans(i,:) = mean(allsynact(((2*i-1)*blocksize+1):((2*i)*blocksize),:));
end

alltaskmean = mean(tasksynact);
allctrlmean = mean(ctrlsynact);

save sepsynact tasksynact ctrlsynact;
save sepmeans taskmeans ctrlmeans alltaskmean allctrlmean;

T = T/2;
nb = nb/2;
save septask T T1 T2 T3 T4 Tb1 Tb2 Tb3 Tblock Ttrial nb nt;
save sepctrl T T1 T2 T3 T4 Tb1 Tb2 Tb3 Tblock Ttrial nb nt;

clear i blocksize;