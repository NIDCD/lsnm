%  loadmovieB_au.m -- 07/16/03
%
%  FORMAT:  m=loadmovieB;
%
%	both hemispheres-separate input for left (gmgn)
%	excitatory regions
%
%  This function loads all the 'out' files needed to make a movie of
%  the neuronal activity in the following brain regions (from left to 
%  right:  MGNs, EA1u, EA2u, STG, ExFS, EFD1, EFD2, ExFR
%  left:   gmgn eg1u eg2u egtg egfs egd1 egd2 egfr;
%
%  Calls:  mov2.m
%
%  It also makes the frames for the movie using the subprogram mov2.m.
%
%  To play the movie, enter movie(m,nt), where m is the loaded movie,
%  and nt is the number of times you want the movie repeated.

%  Written:  07/16/03 by B. Warner
%  Modified from loadmovieB.m (written by T. Long)

%  To add a node: 1. add it to the list of loads. 2. add it to the appropriate array. 3. add it to the clear command. Note that there must be an equal number of movies in left and right. No variables should need to be adjusted.


function m = loadmovieB_au

figure('Position',[200 20 800 200]);
axis('off');

%load right side
load mgns.out;
load ea1u.out;
load ea2u.out;
load estg.out;
load exfs.out;
load efd1.out;
load efd2.out;
load exfr.out;
load epdt.out;

right = [mgns ea1u ea2u estg exfs efd1 efd2 exfr epdt];
clear mgns ea1u ea2u estg exfs efd1 efd2 exfr epdt;

%load left side
load gmgn.out;
load eg1u.out;
load eg2u.out;
load egtg.out;
load egfs.out;
load egd1.out;
load egd2.out;
load egfr.out;
load epdt.out;

left = [gmgn eg1u eg2u egtg egfs egd1 egd2 egfr epdt];
clear gmgn eg1u eg2u egtg egfs egd1 egd2 egfr epdt;

n = length(right(:,1));

m = mov2(left(10:n,:), right(10:n,:),81);






