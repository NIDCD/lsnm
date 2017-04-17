# lsnm_command_line
Command line version of LSNM

The following syntax should be used:

python lsnm.py -m model.txt -w weightslist.txt -s script.py -l lsnm_tvb_link.txt

* lsnm.py is the python script that runs the simulation.
* weightlist.txt contains a list of individual _*.w_ weight files (all should be included in working directory).
* script.py is the script of simulation describing all events in the simulated experiment.
* lsnm_tvb_link.txt is an optional parameter that describes how the LSNM model is embedded into a Virtual Brain (TVB) connectome.

The output is a large number of *.out files in text format that contain time-series of simulated neural and synaptic activity. They are all saved as output files. 
