#include "../include/Algoritm.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> sortColors(const vector<string>& objects, const vector<string>& color_order) {
    // Create dict - id: color 
    unordered_map<string, int> color_priority;
    for (int i = 0; i < color_order.size(); ++i) {
        color_priority[color_order[i]] = i;
    }

    // Create array for count every color
    vector<int> count(color_order.size(), 0);

    // Count colors
    for (const string& obj : objects) {
        if (color_priority.find(obj) != color_priority.end()) {
            count[color_priority[obj]]++;
        }
    }

    // Sorted array
    vector<string> sorted_objects;
    for (int i = 0; i < color_order.size(); ++i) {
        for (int j = 0; j < count[i]; ++j) {
            sorted_objects.push_back(color_order[i]);
        }
    }

    return sorted_objects;
}

void inputData(vector<string>& objects, vector<string>& color_order) {
    string input;

    // Enter colors array
    cout << "Enter colors array (separated by a space): ";
    getline(cin, input);
    objects.clear();
    size_t pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        objects.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    objects.push_back(input);

    // Enter colors order
    cout << "Enter colors order (separated by a space): ";
    getline(cin, input);
    color_order.clear();
    pos = 0;
    while ((pos = input.find(' ')) != string::npos) {
        color_order.push_back(input.substr(0, pos));
        input.erase(0, pos + 1);
    }
    color_order.push_back(input);
}

void printSortedObjects(const vector<string>& sorted_objects) {
    if (sorted_objects.empty()) {
        cout << "Rusult is empty." << endl;
    } else {
        cout << "Sorting colors: ";
        for (const string& obj : sorted_objects) {
            cout << obj << " ";
        }
        cout << endl;
    }
}
