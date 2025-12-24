@echo off
mkdir output 2>nul

g++ -o output/algoritm.exe .\src\Algoritm.cpp .\src\main_app.cpp
g++ -o output/test_color_sorting.exe .\src\Algoritm.cpp .\tests\test_colors_sorting.cpp
g++ -o output/test_stress.exe .\src\Algoritm.cpp .\tests\test_stress_and_memory.cpp

echo.
echo Build complete!
pause