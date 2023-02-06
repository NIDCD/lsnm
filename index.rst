INTRODUCTION
============
The Large-Scale Neural Modeling (LSNM) simulator was developed at the Section on Brain Imaging and Modeling, Voice, Speech and Language Branch, National Institute on Deafness and Other Communication Disorders, National Institutes of Health

The LSNM simulator was developed to model auditory and visual working memory experiments. The Python scripts in LSNM are based on C and Matlab code originally developed by Malle Tagamets and Barry Horwitz to simulate a visual working memory experiment (see Tagamets and Horwitz, 1998 (http://www.ncbi.nlm.nih.gov/pubmed/9651128) and Horwitz and Tagamets, 1999 (http://www.ncbi.nlm.nih.gov/pubmed/10524605)) and by Fatima Husain and Barry Horwitz to simulate an auditory working memory experiment, see Husain et al, 2004 (http://www.ncbi.nlm.nih.gov/pubmed/15050592)). The Python scripts are also based on Barry Horwitz and Brent Warner's functional connectivity simulations (see Horwitz et al, 2005 (http://www.ncbi.nlm.nih.gov/pubmed/16087450)).

The new large-scale neural simulator (LSNM) uses a model, weights, and simulation script. The new LSNM simulator can also work with The Virtual Brain Simulator (https://github.com/the-virtual-brain), and it allows one to embed a neural model into a structural connectome to simulate whole-brain dynamics (Ulloa and Horwitz, 2016) (http://dx.doi.org/10.3389/fninf.2016.00032)).

The old set of programs written in C++ and Matlab to simulate auditory and visual working memory experiments is available at https://github.com/NIDCD/lsnm_in_c, but it is no longer being developed. 

As a historical reference, the LSNM simulator was originally developed by Malle Tagamets and Barry Horwitz in the 1990's to simulate a visual working memory experiment (see Tagamets and Horwitz, 1998 (http://www.ncbi.nlm.nih.gov/pubmed/9651128)) and later adapted/modified by Fatima Husain to simulate an auditory working memory experiment (see Husain et al, 2004 (http://www.ncbi.nlm.nih.gov/pubmed/15050592)). The system was significantly expanded around 2003 by Theresa Long and Barry Horwitz by adding multi-subject simulations and by Brent Warner and Barry Horwitz by adding functional connectivity simulations (see Horwitz et al, 2005 (http://www.ncbi.nlm.nih.gov/pubmed/16087450)). Although the code was originally developed for simulating electrical neuronal activity and PET (Tagamets and Horwitz, 1998 (http://www.ncbi.nlm.nih.gov/pubmed/9651128)), extensions were added to the code to simulate fMRI (Horwitz and Tagamets, 1999 (http://www.ncbi.nlm.nih.gov/pubmed/10524605) and Husain et al, 2004 (http://www.ncbi.nlm.nih.gov/pubmed/15050592)), MEG (Banerjee et al, 2012 (http://www.ncbi.nlm.nih.gov/pubmed/22291621)), and laminar fMRI (Corbitt, Ulloa, and Horwitz, 2018). 

In addition to the code described above, there were other branches of the code made over the years, such as:

* the simulations of Transcranial Magnetic Stimulation (TMS) around 2001 (see Husain et al, 2002 (http://www.ncbi.nlm.nih.gov/pubmed/11771974)), 
* the simulation of perceptual grouping around 2002 (see Husain et al, 2005 (http://www.ncbi.nlm.nih.gov/pubmed/16197683)), 
* the simulations of long-duration auditory stimuli around 2003 (see Ulloa et al, 2008 (http://www.ncbi.nlm.nih.gov/pubmed/19132798)), source code available at https://github.com/NIDCD/lsnm_auditory_sequences), 
* the simulation of a decision-making module around 2004 (see Wen et al, 2008 (http://www.ncbi.nlm.nih.gov/pubmed/18496711), source code available at https://github.com/NIDCD/lsnm_decision_making), and
* the simulation of multiple-item short-term memory (see Liu, Ulloa, and Horwitz, 2018 (http://dx.doi.org/10.1162/jocn_a_01163), source code available at https://github.com/NIDCD/lsnm-multiple-item-stm)


PUBLIC DOMAIN NOTICE
====================

National Institute on Deafness and Other Communication Disorders

This software/database is a "United States Government Work" 
under the terms of the United States Copyright Act. It was 
written as part of the author's official duties as a United 
States Government employee and thus cannot be copyrighted. 
This software/database is freely available to the public for 
use. The NIDCD and the U.S. Government have not placed any 
restriction on its use or reproduction. 

Although all reasonable efforts have been taken to ensure 
the accuracy and reliability of the software and data, the 
NIDCD and the U.S. Government do not and cannot warrant the
performance or results that may be obtained by using this 
software or data. The NIDCD and the U.S. Government disclaim 
all warranties, express or implied, including warranties of 
performance, merchantability or fitness for any particular 
purpose.

Please cite the author in any work or product based on this 
material.

LSNM (Large-Scale Neural Modeling) simulator
============================================

Command line version of LSNM

The following syntax should be used::

   lsnm -m model.txt -w weightslist.txt -s script -l lsnm_tvb_link.txt

* ``lsnm`` is the python script that runs the simulation.
* ``weightlist.txt`` contains a list of individual _*.w_ weight files (all should be included in working directory).
* ``script`` is a python script describing all events in a simulated experiment.
* ``lsnm_tvb_link.txt`` is an optional parameter that describes how the LSNM model is embedded into a Virtual Brain (TVB) connectome.

The output is a large number of *.out files in text format that contain time-series of simulated neural and synaptic activity. They are all saved as output files.

Requirements
============
Python 3.* on a linux OS is required; tested on Python 3.8.12. LSNM has not been tested on non-linux platforms.

How to download / install LSNM
===============================
::

   git clone https://github.com/NIDCD/lsnm.git

How to run the LSNM demo
=========================
::

   cd lsnm
   chmod u+x lsnm
   cd demo
   ../lsnm -m model.txt -w weightslist.txt -s script_DMS_198_seconds

After the last command above you should see the following output::

Start Time:  Mon Feb  6 12:27:51 2023
Building network...
Saving neural network to file...
Running simulation...
Simulation Finished.
Output data files saved.
End Time:  Mon Feb  6 12:34:27 2023

