# Solve traffic congestion using DPC++
This project aims to solve traffic congestion in towns using DPC++. We are living in the age of IoT(Internet Of Things) where every device will be connected to the internet. Imagine that every car is connected to the internet and we can get real-time data of its current position, where its headed and its speed. This can allow us to build a traffic control solution that is proactive as it understands the anticipated current state of the road. It can give priority to congested lanes which have a higher tendency of being congested at peek hours. To process the huge load of data so that we can make decisions at near real-time, we can use heterogenous computing platforms such as Intel DevMesh and DPC++.


# `Make based GPU Project`
A minimal project template for GPU using make build system.

| Optimized for                     | Description
|:---                               |:---
| OS                                | Linux Ubuntu LTS 18.04, 19.10; RHEL 8.x
| Hardware                          | Integrated Graphics from Intel (GPU) GEN9 or higher
| Software                          | Intel(R) oneAPI DPC++ Compiler
| What you will learn               | Get started with compile flow for GPU projects
| Time to complete                  | n/a

## Purpose
This project is a template designed to help you create your own Data Parallel C++ application for GPU targets. The template assumes the use of make to build your application. See the supplied `Makefile` file for hints regarding the compiler options and libraries needed to compile a Data Parallel C++ application for GPU targets. And review the `main.cpp` source file for help with the header files you should include and how to implement the "device selector" code for targeting your application's runtime device.

## Key Implementation Details
The basic DPC++ project template for FPGA targets.

## License
Code samples are licensed under the MIT license. See
[License.txt](https://github.com/oneapi-src/oneAPI-samples/blob/master/License.txt) for details.

Third party program Licenses can be found here: [third-party-programs.txt](https://github.com/oneapi-src/oneAPI-samples/blob/master/third-party-programs.txt)

## Building the `Make based GPU` Program

### Include Files
The include folder is located at %ONEAPI_ROOT%\dev-utilities\latest\include on your development system.

### Running Samples In DevCloud
If running a sample in the Intel DevCloud, remember that you must specify the compute node (CPU, GPU, FPGA) and whether to run in batch or interactive mode. For more information, see the Intel® oneAPI Base Toolkit Get Started Guide (https://devcloud.intel.com/oneapi/get-started/base-toolkit/)

### On a Linux* System
The following instructions assume you are in the root of the project folder.

To build the template using:
```
    make all or make build
```
To run the template using:
```
    make run
```
Clean the template using:
```
    make clean
```
