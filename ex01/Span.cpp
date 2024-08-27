#include "Span.hpp"

Span::Span() : N(5)
{
	std::cout << "this should not be called";
}

Span::Span(unsigned int N) : N(N)
{
}
Span::~Span()
{
}

Span &Span::operator=(const Span &other)
{
	this->numbers = other.numbers;
	this->N = other.N;
	return *this;
}

Span::Span(const Span &other)
{
	*this = other;
}


void Span::addNumber(int number) {
    if (numbers.size() >= N) {
        throw SpanFullException();
    }
    numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (numbers.size() < 2)
	{
		throw NoSpanException();
	}

	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int shortest = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 1; i < sortedNumbers.size() - 1; ++i)
	{
		int span = sortedNumbers[i + 1] - sortedNumbers[i];
		if (span < shortest)
		{
			shortest = span;
		}
	}
	return shortest;
}

int Span::longestSpan()
{
	if (numbers.size() <= 1)
	{
		throw NoSpanException();
	}
	std::sort(numbers.begin(), numbers.end());
	return numbers.back() - numbers.front();
}

