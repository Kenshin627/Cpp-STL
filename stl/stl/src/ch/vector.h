#pragma once
#include <vector>
#include <iostream>
#include <string>

using std::cout, std::endl;
template<typename T>
void PRINT_ELEMENTS(const T& container, const std::string& str)
{
	cout << str << endl;
	for (auto& i : container)
	{
		cout << i << endl;
	}
}

int main()
{
	//assign
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	//with n and elements
	first.assign(10, 5);
	PRINT_ELEMENTS(first, "first: ");

	//with [begin, end)
	second.assign(first.cbegin(), first.cbegin() + 3);
	PRINT_ELEMENTS(second, "second: ");

	//with initializedList
	third.assign({ 1,2,3,4,5 });
	PRINT_ELEMENTS(third, "third: ");
}