#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
#include <climits>
class Span
/**
 * @brief The Span class represents a container that stores a fixed number of integers.
 * 
 * The Span class allows adding numbers to the container, calculating the shortest span between any two numbers,
 * and calculating the longest span between any two numbers.
 */
{
private:
    unsigned int N;
    std::vector<int> numbers;
    Span();

public:
    Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();

template <typename T>
void addMany(T begin, T end) {
    while (begin != end) {
        if (numbers.size() >= N) {
            throw SpanFullException();
        }
        numbers.push_back(*begin);
        ++begin;
    }
}
    class SpanFullException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Container full Exception";
        }
    };

    class NoSpanException : public std::exception
    {
    public:
        const char *what() const throw() 
        {return "No Span Exception";}
    };
};

#endif