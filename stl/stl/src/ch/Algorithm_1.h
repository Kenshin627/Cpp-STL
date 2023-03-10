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

	//transform
	std::vector<int> ivec3{ 1,2,3 };
	std::vector<int> ivec4;
	std::vector<int> ivec5;
	std::transform(ivec3.cbegin(), ivec3.cend(), std::back_inserter(ivec4), [](int val) { return val + 10; });
	std::transform(ivec3.cbegin(), ivec3.cend(), std::back_inserter(ivec5), std::bind(std::multiplies<int>(), std::placeholders::_1, 10));
	PRINT_ELEMENTS(ivec4, "map to ivec4: ");
	PRINT_ELEMENTS(ivec5, "map to ivec5: ");

	//transform combine two coll
	std::vector<int> ivec6{ 1,2,3,4,5 };
	std::transform(ivec6.cbegin(), ivec6.cend(), ivec6.cbegin(), ivec6.begin(), std::multiplies<int>());
	PRINT_ELEMENTS(ivec6, "map to ivec6: ");
}