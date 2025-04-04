# island_perimeter_calculator

## Description

This C++ program calculates the perimeter of an island represented as a 2D grid. The grid is read from an input file (`island_2.txt`), where the island is represented by `1` (land) and `0` (water). The program computes the perimeter by counting the exposed sides of the land cells and writes the result to an output file (`perimeter_1.txt`).

## Features

- Reads a grid of `1`s and `0`s from a text file to represent an island.
- Computes the perimeter of the island by examining the land cells (`1`s) and subtracting the sides shared by neighboring land cells.
- Outputs the perimeter value to an output file.

## File Structure

- **island_2.txt**: Input file containing the 2D grid of `1`s and `0`s, where `1` represents land and `0` represents water.
- **perimeter_1.txt**: Output file that stores the calculated perimeter of the island.
- **island_perimeter.cpp**: The C++ source code that implements the program.

Example Input (island_2.txt): 
5 5
0 0 0 0 0
0 1 1 1 0
0 1 0 1 0
0 1 1 1 0
0 0 0 0 0

Example output(areas.txt):
Perimeter: 12

