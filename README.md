# LSNM (Large-Scale Neural Modeling) simulator
Command line version of LSNM

The following syntax should be used:

```
lsnm -m model.txt -w weightslist.txt -s script -l lsnm_tvb_link.txt
```

* `lsnm` is the python script that runs the simulation.
* `weightlist.txt` contains a list of individual _*.w_ weight files (all should be included in working directory).
* `script` is a python script that describes all events in the simulated experiment.
* `lsnm_tvb_link.txt` is an optional parameter that describes how the LSNM model is embedded into a Virtual Brain (TVB) connectome.

The output is a number of *.out files in text format that contain time-series of simulated neural and synaptic activity.

## Requirements

## How to download / install LSNM:
```
git clone https://github.com/NIDCD/lsnm.git
```

## How to run the LSNM demo:
```
cd lsnm
chmod u+x lsnm
cd demo
../lsnm -m model.txt -w weightslist.txt -s script_DMS_198_seconds
```

After the last command above you should see the following output:
```
Start Time:  Mon Feb  6 12:27:51 2023
Building network...
Saving neural network to file...
Running simulation...
Simulation Finished.
Output data files saved.
End Time:  Mon Feb  6 12:34:27 2023

```

## How to run the LSNM demo embedded in The Virtual Brain (TVB)
To run LSNM and TVB together you will need to build a conda environment that contains the TVB packages along with its dependencies. The TVB packages can be downloaded from the TVB github repository at: https://github.com/the-virtual-brain/tvb-root. After you have built the TVB enviroment, simply run LSNM as follows:
```
../lsnm -m model.txt -w weightslist.txt -s script_DMS_198_seconds -l lsnm_tvb_link.txt 
```
