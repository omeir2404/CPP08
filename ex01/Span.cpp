#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->numbers = std::vector<int>(N);
}
Span::~Span()
{
}

void Span::addNumber(int Number){
	if(this->numbers.capacity() > 0)
		this->numbers.push_back(Number);
}