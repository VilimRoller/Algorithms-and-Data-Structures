# Algorithms-and-Data-Structures
## Table of Contents
- [Introduction](#introduction)
- [List of Algorithms and Data Structures](#list-of-algorithms-and-data-structures)
- [Installation](#installation)
- [Unit Tests](#unit-tests)
- [Running Benchmark](#running-benchmark)
- [Modifying Benchmark](#modifying-benchmark)
## Introduction
This project includes an implementation of algorithms and data structures in C++, and a benchmark used to compare their performance.

## List of Algorithms and Data Structures

| Search Algorithms       | Sort Algorithms        | Data Structures  |
| ----------------------- | ---------------------- | ---------------- |
| Binary Search           | Bubble Sort            | Vector           |
| Interpolation Search    | Heap Sort              | Stack            |
| Jump Search             | Insertion Sort         | Queue            |
| Linear Search           | Merge Sort             |                  |
|                         | Quick Sort             |                  |
|                         | Selection Sort         |                  |
|                         | Shell Sort             |                  |

## Installation
1. Clone the repository
```
git clone https://github.com/VilimRoller/Algorithms-and-Data-Structures.git
```
2. Navigate to `AlgorithmsAndDataStructures` directory
3. Build the project
```
cmake . .
```
4. Compile the project
```
make
```
## Unit tests
To run the unit tests, run:
```
./AlgorithmsAndDataStructures/tst/AlgorithmsAndDataStructuresTests
```
## Running Benchmark
To run the benchmark, run:
```
./AlgorithmsAndDataStructures/src/AlgorithmsAndDataStructures
```

The benchmark generates two files in the `AlgorithmsAndDataStructures` directory:
- `Search Algorithms Benchmark.txt`
- `Uniform distribution benchmark results.txt`

Name of the Sort Algorithm benchmark output depends on distribution type used for generating data.

You can use `PlotData.py` script located in the root directory to visualize the benchmark results:
```
python3 PlotData.py
```
## Modifying Benchmark
You can modify the benchmarks input in `AlgorithmsAndDataStructures/src/main.cpp`.
The benchmarks supports the following input parameters:

#### Number of vector sizes
The number of vector sizes represents the count of vectors used in the benchmark.

#### Vector size step
The vector size step denotes the increment value for vector sizes. For example, with a vector size step of 10, the vector sizes used for searching or sorting would be 10, 20, 30, and so on.

#### Distribution types
The distribution types are applicable only to the Sort Algorithms Benchmark, as the Search Algorithms Benchmark employs sorted vectors. The distribution type determines the type of distribution used when generating data. 

Supported distribution types include:

|                         |                        |                         |
| ----------------------- | ---------------------- | ----------------------- |
| Uniform                 | Binomial               | Negative Binomial       |
| Geometric               | Poisson                | Exponential             |
| Gamma                   | Weibull                | Extreme Value           |
| Normal                  | Log-Normal             | Chi-Squared             |
| Cauchy                  | F-distibution          | Student t-distribution  |


The `DistributionType::NO_DISTRIBUTION` type can be used to populate vectors with random values without employing any of the mentioned distributions.

