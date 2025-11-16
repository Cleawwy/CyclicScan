# C-SCAN Scheduler

A minimal C++ implementation of the C-SCAN disk scheduling algorithm for tracks 0–199. The program processes an initial arm position, movement direction, and a list of track requests, then simulates the full seek cycle including wrap-around.

## Overview

This program:

* Accepts user input for the initial head position and direction (UP / DOWN)
* Accepts a list of track requests
* Sorts all requests in ascending order
* Simulates C-SCAN by servicing requests in the specified direction
* Wraps around to the opposite end of the disk and continues serving
* Computes total track distance travelled

## How to Build

```
Build Instructions
------------------
Compiler: g++ (C++17 or newer)
Build Command:
    g++ main.cpp -o cscan
Run Command:
    ./cscan
```

## Usage

1. Run the compiled executable.
2. Enter initial arm position (0–199).
3. Enter direction: UP or DOWN.
4. Enter the list of track requests.
5. View the full step-by-step seek simulation and total distance travelled.

## Example Input Format

```
Initial Arm Position: 50
Direction: UP
Requests: 85 10 37 175 112 24 73 52 183 149
```

## Example Output Box

```
Start   Finished   Track Travelled
50      52         nn
52      73         nn
73      85         .
85      112        .
112     149        .
149     175        .
175     183        .
183     199        .
199     0          ..
0       10         nn
10      24         nn
24      37         nn
---------------------------
Total Track Travelled: xx
```

## Files

```
main.cpp
```

## Requirements

* Standard C++ compiler
* No external libraries required
