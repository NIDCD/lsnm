# LSNM (Large-Scale Neural Modeling) Brain Simulator
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

### Core Dependencies
- Python 3.6 or higher
- NumPy >= 1.19.0
- Standard Python libraries (re, random, math, json, time, sys, argparse, importlib)

### Optional Dependencies (for TVB Integration)
- The Virtual Brain (TVB) packages
  - tvb-simulator
  - tvb-datatypes
  - tvb-plot
  - tvb-library

Note: For TVB integration, it's recommended to use a conda environment with TVB packages installed from the [TVB repository](https://github.com/the-virtual-brain/tvb-root).

## Docker Setup

### Building and Running with Docker

1. Build the Docker image:
```bash
docker build -t lsnm .
```

2. Run the Docker container:
```bash
docker run -it --rm lsnm
```

This will start a container with:
- All required dependencies installed
- A conda environment named 'lsnm' with all necessary packages
- The LSNM simulator ready to use

### Using the Conda Environment in Docker

The Docker container comes with a pre-configured conda environment. To use it:

1. Start the container:
```bash
docker run -it --rm lsnm
```

2. The conda environment is automatically activated. You can verify this by running:
```bash
conda env list
```

3. To run the demo:
```bash
demo/run_demo.sh
```

### Mounting Local Directories

To work with local files, you can mount directories when running the container:

```bash
docker run -it --rm -v $(pwd):/app lsnm
```

This will mount your current directory to /app in the container, allowing you to:
- Access local files
- Save output files to your local system
- Modify and test code changes

## How to download / install LSNM:
```
git clone https://github.com/NIDCD/lsnm.git
```

## How to run the LSNM demo:
```
cd lsnm
chmod u+x lsnm
cdmod u+x demo/run_demo
demo/run_demo
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

## How to Learn Weights for LSNM

The `learn_weights.py` script trains a neural network to generate weights for the LSNM model. These weights can then be used to simulate brain activity.

### Usage
To learn the weights, run:
```bash
python learn_weights.py --dataset <path_to_dataset> --output <output_weights_file>
```

## Command Line Arguments

--model: Path to model description file (txt). This file describes the network architecture 
        including all modules, their dimensions, and parameters for the Wilson-Cowan equations.
--weights: Path to weights list file (txt). Traditional weights format.
--pytorch-weights: Path to PyTorch weights file (.pth). Alternative to --weights.
--script: Path to simulation script (py).
--links: Path to TVB connectome links file (txt). Optional.

Note: You must specify either --weights OR --pytorch-weights, but not both.