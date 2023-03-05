#pragma once
#include <array>
#include <iostream>
#include <string>
#include <tuple>

using std::cout, std::endl;

template<typename T>
void PRINT_ELEMENTS(const T& container, const std::string& str)
{
	std::cout << str << std::endl;
	for (auto& i : container)
	{
		cout << i << endl;
	}
}

int main()
{
	//³õÊ¼»¯
	std::array<std::string, 5> fiveStrings = { "hello", "nico", "how", "are", "you" };

	std::array<std::string, 5> fiveStrings2({ "hello", "nico", "how", "are", "you" });

	PRINT_ELEMENTS(fiveStrings2, "fiveStrings: ");
	PRINT_ELEMENTS(fiveStrings2, "fiveStrings2: ");

	//tuple interface
	cout << "size of fiveStrings: " << std::tuple_size<std::array<std::string, 5>>::value << endl; //size
	std::tuple_element<0, decltype(fiveStrings)>::type typeEle = "123"; //get element type
	cout << "type of elements 0: " << typeEle << endl;
	cout << "element 1 of array is: " << std::get<1>(fiveStrings) << endl; //get element value

	//examples
	std::array<int, 10> a = { 11,22,33,44 };
	PRINT_ELEMENTS(a, "initialized: ");
	a.back() = 999999;
	a[a.size() - 2] = 42;
	PRINT_ELEMENTS(a, "modifly: ");
}