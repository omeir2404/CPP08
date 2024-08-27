#include <iostream>
#include <vector>
#include <algorithm>
#include "easyfind.hpp"


// Simple assertion function
void assertTest(bool condition, const std::string& testName, const std::string& message) {
    if (condition) {
        std::cout << "[PASS] " << testName << std::endl;
    } else {
        std::cout << "[FAIL] " << testName << ": " << message << std::endl;
    }
}

void testElementExists() {
    int arr1[] = {1, 2, 3, 4, 5};
    std::vector<int> numbers(arr1, arr1 + 5);
    int target = 3;
    std::vector<int>::iterator result = easyfind(numbers, target);
    assertTest(result != numbers.end(), "testElementExists", "Element should exist");
}

void testElementDoesNotExist() {
    int arr1[] = {1, 2, 3, 4, 5};
    std::vector<int> numbers(arr1, arr1 + 5);
    int target = 6;
    try {
        std::vector<int>::iterator result = easyfind(numbers, target);
        assertTest(result == numbers.end(), "testElementDoesNotExist", "Element should not exist");
    } catch (const std::runtime_error &e) {
        assertTest(true, "testElementDoesNotExist", e.what());
    }
}

void testElementExistsInEmptyVector() {
    std::vector<int> emptyVector;
    int target = 10;
    try {
        std::vector<int>::iterator result = easyfind(emptyVector, target);
        assertTest(result == emptyVector.end(), "testElementExistsInEmptyVector", "Empty vector should not contain any elements");
    } catch (const std::runtime_error &e) {
        assertTest(true, "testElementExistsInEmptyVector", e.what());
    }
}

int main() {
    testElementExists();
    //either of these two below will fail and throw an exception
    testElementDoesNotExist();
    testElementExistsInEmptyVector();
    return 0;
}