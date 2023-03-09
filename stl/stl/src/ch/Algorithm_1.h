#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using std::cout, std::endl;
template<typename T>
void PRINT_ELEMENTS(const T& container, const std::string& prefix)
{
	cout << prefix << endl;
	for (auto& i : container)
	{
		cout << i << endl;
	}
}

int main()
{
	//mismatch
	std::vector<int> ivec{ 1,2,3,4,5,6,7 };
	std::vector<int> ivec1{ 1,2,4,5,6,7,8 };
	std::vector<int> ivec2{ 1,2,3,4,5,6,7,8,9,10,11 };

	auto ret = std::mismatch(ivec.cbegin(), ivec.cend(), ivec1.cbegin(), [](int val1, int val2) { return val1 == val2; });
	auto ret1 = std::mismatch(ivec.cbegin(), ivec.cend(), ivec2.cbegin());
	if (ret.first != ivec.cend())
	{
		cout << "first mismatch: " << *ret.first << "," << *ret.second << endl;
	}
	else {
		cout << "not mismatch" << endl;
	}

	if (ret1.first != ivec.cend())
	{
		cout << "first mismatch: " << *ret.first << "," << *ret.second << endl;
	}
	else {
		cout << "not mismatch" << endl;
	}
}