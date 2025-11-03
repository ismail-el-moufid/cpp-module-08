#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{

	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 2);

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 2);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}