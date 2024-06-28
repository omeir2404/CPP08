#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    std::vector<int> numbers(array, array + 5);

    // Test case 1: Element exists in the vector
    int target1 = 3;
    auto result1 = easyfind(numbers, target1);
    if (result1 != numbers.end())
    {
        std::cout << "Element " << target1 << " found at index " << std::distance(numbers.begin(), result1) << std::endl;
    }
    else
    {
        std::cout << "Element " << target1 << " not found" << std::endl;
    }

    // Test case 2: Element does not exist in the vector
    int target2 = 6;
    auto result2 = easyfind(numbers, target2);
    if (result2 != numbers.end())
    {
        std::cout << "Element " << target2 << " found at index " << std::distance(numbers.begin(), result2) << std::endl;
    }
    else
    {
        std::cout << "Element " << target2 << " not found" << std::endl;
    }

    // Test case 3: Element exists multiple times in the vector
    // Test case 3: Empty vector
    std::vector<int> emptyVector;
    int target3 = 10;
    auto result3 = easyfind(emptyVector, target3);
    if (result3 != emptyVector.end())
    {
        std::cout << "Element " << target3 << " found at index " << std::distance(emptyVector.begin(), result3) << std::endl;
    }
    else
    {
        std::cout << "Element " << target3 << " not found" << std::endl;
    }
    int target3 = 4;
    auto result3 = easyfind(numbers, target3);
    if (result3 != numbers.end())
    {
        std::cout << "Element " << target3 << " found at index " << std::distance(numbers.begin(), result3) << std::endl;
    }
    else
    {
        std::cout << "Element " << target3 << " not found" << std::endl;
    }
    return 0;
}