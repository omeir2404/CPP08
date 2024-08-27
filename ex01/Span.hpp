#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class Span
{
private:
    unsigned int N;
    std::vector<int> numbers;

public:
    Span(unsigned int N);
    ~Span();

    void addNumber(int number);
};

#endif