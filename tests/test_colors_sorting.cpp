#include <windows.h>

#include <iostream>
#include <vector>
#include "../include/Algoritm.h"

using namespace std;

// Macros for tests
#define CHECK_EQUAL(actual, expected, test_case_number, test_name, objects, color_order, expected_result, line_number) { \
    cout << "=======================================" << endl; \
    if ((actual) == (expected)) { \
        cout << "————— Test case " << test_case_number << " - PASSED. ——————" << endl; \
        cout << "—————————————————————" << endl; \
        cout << "NAME: " << test_name << endl; \
        cout << "Input array: "; \
        for (const auto& obj : objects) cout << obj << " "; \
        cout << endl; \
        cout << "Input order: "; \
        for (const auto& order : color_order) cout << order << " "; \
        cout << endl; \
        cout << "———————————" << endl; \
        cout << "Expected result: "; \
        for (const auto& exp : expected_result) cout << exp << " "; \
        cout << endl; \
        cout << "Actual result: "; \
        for (const auto& act : actual) cout << act << " "; \
        cout << endl; \
    } else { \
        cout << "—— WARNING!!!  Test case " << test_case_number << " - FAILED. ——" << endl; \
        cout << "—————————————————————" << endl; \
        cout << "NAME: " << test_name << endl; \
        cout << "Input array: "; \
        for (const auto& obj : objects) cout << obj << " "; \
        cout << endl; \
        cout << "Input order: "; \
        for (const auto& order : color_order) cout << order << " "; \
        cout << endl; \
        cout << "———————————" << endl; \
        cout << "Expected result: "; \
        for (const auto& exp : expected_result) cout << exp << " "; \
        cout << endl; \
        cout << "Actual result: "; \
        for (const auto& act : actual) cout << act << " "; \
        cout << endl; \
        cout << "————————————" << endl; \
        cout << "TEST FAILED - IN LINE " << line_number << "." << endl; \
    } \
    cout << "=======================================" << endl; \
}

// Function to compare vectors
bool compareVectors(const vector<string>& v1, const vector<string>& v2) {
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}


// Function to check if one of the expected results matches the actual result
vector<string> findExpectedMatch(const vector<vector<string>>& expectedList, const vector<string>& actual) {
    for (const auto& expected : expectedList) {
        if ((actual) == (expected)) {
            return expected;
        }
    }
    return {"Error"};
}

void baseTest(){
    {
        // 1. Basic colors sorting
        vector<string> objects = {"С", "С", "З", "С", "К", "З", "З", "З", "К", "К", "С", "З", "С", "С", "К", "З"};
        vector<string> color_order = {"З", "С", "К"};
        vector<string> expected = {"З", "З", "З", "З", "З", "З", "С", "С", "С", "С", "С", "С", "К", "К", "К", "К"};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 1, "Basic colors sorting", objects, color_order, expected, __LINE__);
    };

    {
        // 2. Empty colors array sorting
        vector<string> objects = {};
        vector<string> color_order = {"З", "С", "К"};
        vector<string> expected = {"Error: Please, enter current colors."};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 2, "Empty colors array sorting", objects, color_order, expected, __LINE__);
    };

    {
        // 3. One element sorting
        vector<string> objects = {"С"};
        vector<string> color_order = {"З", "С", "К"};
        vector<string> expected = {"С"};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 3, "One element sorting", objects, color_order, expected, __LINE__);
    };

    {
        // 4. One color elements sorting
        vector<string> objects = {"К", "К"};
        vector<string> color_order = {"З", "С", "К"};
        vector<string> expected = {"К", "К"};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 4, "One color elements sorting", objects, color_order, expected, __LINE__);
    };

    {
        // 5. Sorting elements with symbols
        vector<string> objects = {"-С", "@С", "!К+"};
        vector<string> color_order = {"З", "С", "К"};
        vector<string> expected = {"Error: Please, enter current colors."};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 5, "Sorting elements with symbols", objects, color_order, expected, __LINE__);
    };

    {
        // 6. Sorting elements with numbers
        vector<string> objects = {"С", "5", "К"};
        vector<string> color_order = {"З", "С", "К"};
        vector<string> expected = {"С", "К"};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 6, "Sorting elements with numbers", objects, color_order, expected, __LINE__);
    };

    {
        // 7. Inverse colors array
        vector<string> objects = {"К", "К", "К", "С", "С", "С", "З", "З", "З"};
        vector<string> color_order = {"З", "С", "К"};
        vector<string> expected = {"З", "З", "З", "С", "С", "С", "К", "К", "К"};   
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 7, "Inverse colors array", objects, color_order, expected, __LINE__);
    };
    
    {
        // 8. Random order colors
        vector<string> objects = {"С", "К", "З", "С", "К", "З"};
        vector<string> color_order = {"К", "З", "С"};
        vector<string> expected = {"К", "К", "З", "З", "С", "С"};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 8, "Random order colors", objects, color_order, expected, __LINE__);
    };

    {
        // 9. Two colors order
        vector<string> objects = {"С", "З", "К", "С", "З", "З"};
        vector<string> color_order = {"З", "С"};
        vector<string> expected = {"З", "З", "З", "С", "С"};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 9, "Two colors order", objects, color_order, expected, __LINE__);
    };

    {
        // 10. Unknown color element in array
        vector<string> objects = {"С", "К", "З", "С", "Ф"};
        vector<string> color_order = {"З", "С", "К"};
        vector<string> expected = {"З", "С", "С", "К"};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 10, "Unknown color element in array", objects, color_order, expected, __LINE__);
    };

    {
        // 11. Empty colors order
        vector<string> objects = {"З", "С", "К"};
        vector<string> color_order = {};
        vector<string> expected = {"Error: Please, enter color order."};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 11, "Empty colors order", objects, color_order, expected, __LINE__);
    };

    {
        // 12. Upper and lower colors elements
        vector<string> objects = {"к", "З", "с", "С", "с", "З", "з", "к", "з", "К"};
        vector<string> color_order = {"с", "З", "к"};
        vector<string> expected = {"с", "с", "З", "З", "к", "к"};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 12, "Upper and lower colors elements", objects, color_order, expected, __LINE__);
    };

    {   
        // 13. Incurrent colors array
        vector<string> objects = {"кК", "сЗ"};
        vector<string> color_order = {"К", "З", "С"};
        vector<string> expected = {"Error: Please, enter current colors."};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 13, "Incurrent colors array", objects, color_order, expected, __LINE__);
    };

    {   
        // 14. Limit colors array
        vector<string> objects = {61, "З"};
        vector<string> color_order = {"К", "З", "С"};
        vector<string> expected = {"Error: Enter very large colors array (min: 1, maximum: 60)."};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 14, "Limit colors array", objects, color_order, expected, __LINE__);
    };

    {   
        // 15. Incorrect array
        vector<string> objects = {"Error!", "Oh!", "Oh!", "Error!", "Oh!", "Error!"};
        vector<string> color_order = {"Oh!", "Error!"};
        vector<string> expected = {"Error: Please, enter current colors."};
        vector<string> result = sortColors(objects, color_order);
        CHECK_EQUAL(result, expected, 15, "Incorrect array", objects, color_order, expected, __LINE__);
    }

}

int main() {

    // decode UTF-8
    SetConsoleOutputCP(CP_UTF8);

    baseTest();

    // Output in cmd
    #ifdef _WIN32
        system("pause");
    #endif

    return 0;
}
