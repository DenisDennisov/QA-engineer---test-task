# Color Sorting Algorithm

A simple C++ program that sorts an array of color identifiers according to a custom order. The project includes the core algorithm, a correctness test suite, and a stress/memory test.
#### The application is created as a portfolio.

## How to building

> **Requirement**: MinGW-w64 or any GNU-compatible C++ compiler (`g++`) installed and added to `PATH`.

1. Open a terminal in the project root directory.
2. Run the build script:
```bat
build.bat
```
This will generate three executables in the output/ folder:

algoritm.exe — interactive sorting application
test_color_sorting.exe — correctness test suite
test_stress.exe — stress and performance test

On Windows, you can also double-click build.bat in File Explorer.

## Running the Programs
After compiling the files to exe, go to the "outputs" folder. 
3 files should be compiled:
```bat
- algorithm.exe
- test_color_sorting.exe
- test_stress.exe
```
### 1. algorithm.exe
The algorithm sorts the colors in a given order.
#### Example:
Input a list of colors and press Enter:
```bat
R G G B G B R R B G
```
Input the desired sort order and press Enter:
```bat
G R B
```
#### Result:
```bat
Sorting colors: G G G G R R R B B B
```
### 2. test_color_sorting.exe
Runs all possible tests for the algorithm.
#### Example:
Passed test.
```bat
————— Test case 1 - PASSED. ——————
—————————————————————
NAME: Basic colors sorting
Input array: С С З С К З З З К К С З С С К З
Input order: З С К
———————————
Expected result: З З З З З З С С С С С С К К К К
Actual result: З З З З З З С С С С С С К К К К
```
Failed test.
```bat
—— WARNING!!!  Test case 2 - FAILED. ——
—————————————————————
NAME: Empty colors array sorting
Input array:
Input order: З С К
———————————
Expected result: Error: Please, enter current colors.
Actual result:
————————————
TEST FAILED - IN LINE 88.
```
### 3. test_stress.exe
Measures code execution time.
#### Example:
Input the number of random colors the test will generate (max 10 million!) and press Enter.
#### Sorting speed result of 10,000 elements
```bat
Generated color: К
Generated color: З
Generated color: С
Generated color: С
Generated color: К
Generated color: З
Generated color: К
Generated color: С
Generated color: К
Generated color: К
Generated color: С
Generated color: З
Generated color: З
Generated color: З
Generated color: К
Stress Test Summary:
========================
Number of elements sorted: 10000 elements.
Time taken: 0 min 0 sec 0 ms
Time per element: 0 ms
First 10 sorted elements: З З З З З З З З З З
Last 10 sorted elements: К К К К К К К К К К
```
## Test documentation
The test project also contains test documentation that I created in the "Test documentation" folder.
## Notes
The core algorithm uses counting sort for O(n) time complexity.
All input and output support UTF-8 (Russian characters displayed correctly on Windows).
