# CANON: Differentiated Partial Failure Resilience for Ephemeral Data Systems over Disaggregated Shared Memory

## Setup & Usage

```
git clone this_repo
cd this_repo
git submodule update --init --recursive

# compile CLHT
cd CLHT && ./prepare_everything.sh
cd ..

# lib preparation (ubuntu as an example)
sudo apt update
sudo apt install cmake libtbb-dev numactl

# compile project
./prepare.sh

# fill param in run.py and then test by yourself
python run_no_trace.py
```
