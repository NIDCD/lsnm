%  topfmrigen_2.m
%
%  FORMAT topfmrigen_2
% 
%  ___________________________________
%
%  This program, for each subject, goes through the directories
%  and generates the hemodynamically-delayed fMRI activity corresponding to
%  the integrated synaptic activity.  It does this separately for the task
%  condition and the control condition.
%
%  Calls fmrigen_2.m
%        subjectlist.mat,scanparam.mat,sepsynact.mat,sepctrl.mat
%
%------------------------------------------------------------------

%  Written July 2003 by B. Warner

load subjectlist
[nsub nsubc]=size(subjectlist);
workdir=pwd;
load scanparam

for iis=1:nsub
	eval(['cd ',subjectlist(iis,:)])
	load sepsynact_fmri
	load septask
	allsynact=tonesynact;
	fmrigen_2
	fmridata=fmriact2(5:end,:);
	save fmritone fmridata
        allsynact=TCsynact;
	fmrigen_2
	fmridata=fmriact2(5:end,:);
	save fmriTC fmridata
	allsynact=ctrlsynact;
	fmrigen_2
	fmridata=fmriact2(5:end,:);
	save fmrictrl fmridata
	eval(['cd ',workdir])
end
	