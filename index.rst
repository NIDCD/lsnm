LSNM (Large-Scale Neural Modeling) simulator
============================================

Command line version of LSNM

The following syntax should be used::

   lsnm -m model.txt -w weightslist.txt -s script.py -l lsnm_tvb_link.txt

* ``lsnm`` is the python script that runs the simulation.
* ``weightlist.txt`` contains a list of individual _*.w_ weight files (all should be included in working directory).
* ``script.py`` is the script of simulation describing all events in the simulated experiment.
* ``lsnm_tvb_link.txt`` is an optional parameter that describes how the LSNM model is embedded into a Virtual Brain (TVB) connectome.

The output is a large number of *.out files in text format that contain time-series of simulated neural and synaptic activity. They are all saved as output files.

Requirements
============
Python 2.7 on a linux OS is required. LSNM has not been tested on non-linux platforms.

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
   ../lsnm -m model.txt -w weightslist.txt -s script_DMS_198_seconds.py

After the last command above you should see the following output::

   Start Time:  Tue Jan 24 15:09:41 2023
   Building network...
   Saving neural network to file...
   Running simulation...
   Simulation Finished.
   Output data files saved.
   End Time:  Tue Jan 24 15:21:13 2023
