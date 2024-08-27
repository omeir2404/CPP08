#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void testAddNumber() {
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    assert(sp.shortestSpan() == 2);
    assert(sp.longestSpan() == 14);
}

void testAddMany() {
    int numbersArray[] = {1, 2, 3, 4, 5};
    std::vector<int> numbers(numbersArray, numbersArray + sizeof(numbersArray) / sizeof(int));
    Span sp(10);
    sp.addMany(numbers.begin(), numbers.end());
    sp.addNumber(6);
    sp.addNumber(7);
    sp.addNumber(8);
    sp.addNumber(9);
    sp.addNumber(10);
    assert(sp.shortestSpan() == 1);
    assert(sp.longestSpan() == 9);
}

void testFullContainerException() {
    Span sp(3);
    sp.addNumber(1);
    sp.addNumber(2);
    sp.addNumber(3);
    try {
        sp.addNumber(4);
        assert(false); // Should not reach here
    } catch (const Span::SpanFullException &e) {
        assert(true); // Exception should be thrown
    }
}

void testNoSpanException() {
    Span sp(3);
    sp.addNumber(1);
    try {
        sp.shortestSpan();
        assert(false); // Should not reach here
    } catch (const Span::NoSpanException &e) {
        assert(true); // Exception should be thrown
    }
}

void testLargeNumberOfElements() {
    Span sp(10000);
    for (int i = 0; i < 10000; ++i) {
        sp.addNumber(i);
    }
    assert(sp.shortestSpan() == 1);
    assert(sp.longestSpan() == 9999);
}


void testLargeNumberOfRandomElements() {
    Span sp(10000);
    std::vector<int> randomNumbers(10000);

    std::srand(std::time(0)); 

    for (size_t i = 0; i < randomNumbers.size(); ++i) {
        randomNumbers[i] = std::rand() % 100000 + 1; 
    }

    sp.addMany(randomNumbers.begin(), randomNumbers.end());

    assert(sp.shortestSpan() >= 0);
    assert(sp.longestSpan() >= 0); 
}

int main() {
    testAddNumber();
    testAddMany();
    testFullContainerException();
    testNoSpanException();
    testLargeNumberOfElements();
    testLargeNumberOfRandomElements();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}