#define NOMINMAX
#include <windows.h>

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include "../include/Algoritm.h"

using namespace std;

vector<string> generateLargeDataset(int size) {
    vector<string> dataset;
    vector<string> colors = {"З", "С", "К"};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0, 2);
    for (int i = 0; i < size; ++i) {
        string color = colors[distr(gen)];
        dataset.push_back(color);
        cout << "Generated color: " << color << endl;
    }
    return dataset;
}

void stressTest(int numElements) {
    vector<string> colorOrder = {"З", "С", "К"};

    // Generate large random array of colors
    vector<string> largeData = generateLargeDataset(numElements);

    // Start timer
    auto start = chrono::high_resolution_clock::now();

    // Start algorithm
    vector<string> sorted = sortColors(largeData, colorOrder);

    // Stop timer
    auto end = chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    int minutes = duration.count() / 60000;
    int seconds = (duration.count() % 60000) / 1000;
    int milliseconds = duration.count() % 1000;

    // Output test result 
    cout << "Stress Test Summary:" << endl;
    cout << "========================" << endl;
    cout << "Number of elements sorted: " << largeData.size() << " elements." << endl;
    cout << "Time taken: " << minutes << " min " << seconds << " sec " << milliseconds << " ms" << endl;
    cout << "Time per element: " << (duration.count() / static_cast<double>(largeData.size())) << " ms" << endl;
    
    // Output first and last 10 sorted elements
    cout << "First 10 sorted elements: ";
    for (int i = 0; i < 10 && i < sorted.size(); ++i) {
        cout << sorted[i] << " ";
    }
    cout << endl;

    cout << "Last 10 sorted elements: ";
    for (int i = sorted.size() - 10; i < sorted.size(); ++i) {
        cout << sorted[i] << " ";
    }
    cout << endl;
}


int main() {

    // decode UTF-8
    SetConsoleOutputCP(CP_UTF8);

    int numElements;
    cout << "Enter the number of elements to generate (max 10 million): ";
    while (!(cin >> numElements) || numElements < 1 || numElements > 10000000) {
        cout << "Invalid input. Please enter a number between 1 and 10000000: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Run stress test with the provided number of elements
    stressTest(numElements);

    // Output in cmd
    #ifdef _WIN32
        system("pause");
    #endif

    return 0;
}
