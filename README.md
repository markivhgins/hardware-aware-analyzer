# Hardware-Aware Algorithm Performance Analyzer

A systems-level benchmarking tool that analyzes algorithm performance beyond Big-O complexity using hardware performance counters.

---

## Overview

Traditional algorithm analysis focuses on theoretical time complexity (O(n), O(n log n), etc.), but real-world performance depends heavily on hardware behavior.

This project measures:

* Execution time
* CPU cycles
* Instructions executed
* Cache misses
* Branch mispredictions

---

## Key Idea

Two algorithms with the same time complexity can perform very differently due to:

* Cache locality
* Memory access patterns
* Branch prediction efficiency

---

## Experiments Implemented

### 1. Array vs Linked List

* Demonstrates cache locality
* Array → contiguous memory (fast)
* Linked list → scattered memory (slow)

---

### 2. Matrix Multiplication

* Naive (i, j, k)
* Optimized (i, k, j)
* Shows impact of memory access patterns

---

### 3. Branch Prediction

* Predictable branch
* Random branch
* Demonstrates CPU pipeline behavior

---

## Metrics Collected

* Execution Time (ms)
* CPU Cycles
* Instructions
* Cache Misses
* Branch Misses

---

## Tech Stack

* C (low-level systems programming)
* Linux perf_event_open API
* GCC
* POSIX timing (clock_gettime)

---

## Build Instructions

gcc -Isrc/include 
src/main.c 
src/runner.c 
src/metrics/timer.c 
src/metrics/perf.c 
src/algorithms/array.c 
src/algorithms/linkedlist.c 
src/algorithms/matrix.c 
src/algorithms/branch.c 
-o analyzer

---

## Usage

./analyzer <experiment> <size> <runs>

---

## Examples

./analyzer array 1000000 5
./analyzer linkedlist 1000000 5

./analyzer matrix_naive 256 3
./analyzer matrix_opt 256 3

./analyzer branch_pred 100000000 3
./analyzer branch_rand 100000000 3

---

## Requirements

Linux system with perf support.

If you get permission errors:

sudo sysctl -w kernel.perf_event_paranoid=1

---

## Sample Output

Run 1: 200.123 ms | Cycles: 123456789 | Instructions: ... | Cache Misses: ... | Branch Misses: ...

---

## Key Insights

* Cache locality significantly affects performance
* Memory access patterns matter more than complexity in some cases
* Branch misprediction causes measurable slowdowns
* Hardware behavior explains real-world performance differences

---

## Future Work

* CSV logging
* Graph visualization
* Statistical analysis (variance, std dev)
* Web-based dashboard

---

## License

This project is licensed under the MIT License.

Made for educational purposes. 

---

## Author

Vikram Singh 
