#include <iostream>
#include <vector>
#include "../include/Algoritm.h"

using namespace std;

int main() {
    vector<string> objects;
    vector<string> color_order;

    // Input colors array and order
    inputData(objects, color_order);

    string user_input;
    while (true) {
        // Sorting array and output result
        vector<string> sorted_objects = sortColors(objects, color_order);
        printSortedObjects(sorted_objects);

        // Ask user wants to enter new colors array for sorting
        cout << "Do you have enter new colors array for sorting? (y/n[any key]): ";
        getline(cin, user_input);

        if (user_input == "y" || user_input == "Y") {
            inputData(objects, color_order);
        } else {
            break;
        }
    }
    return 0;
}