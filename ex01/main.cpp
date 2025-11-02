#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp(100001);

	for (int i = 0; i <= 100000; i++)
		sp.addNumber(i * 3);

	try
	{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}