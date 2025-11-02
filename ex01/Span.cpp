#include "Span.hpp"
#include <algorithm>
#include <vector>


Span::Span() : maxSize(0) {}

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		numbers = other.numbers;
		maxSize = other.maxSize;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (numbers.size() >= maxSize)
		throw std::out_of_range("Span is full");
	numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan()
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	int minNumber = *std::min_element(numbers.begin(), numbers.end());
	int maxNumber = *std::max_element(numbers.begin(), numbers.end());

	return maxNumber - minNumber;
}