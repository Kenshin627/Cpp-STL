#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

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

class BothSpace
{
public:
	bool operator()(const char& c1, const char& c2)
	{
		return c1 == ' ' && c2 == ' ';
	}
};

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

	//fill_n
	std::fill_n(std::ostream_iterator<int>(cout, " "), 10, 7);

	//generate_n
	int val = 1;
	std::generate_n(std::ostream_iterator<int>(cout, " "), 10, [=]()mutable {return val++; });

	//iota
	std::vector<int> ivec7(10);
	std::iota(ivec7.begin(), ivec7.end(), 1);
	PRINT_ELEMENTS(ivec7, "iota: ");

	//replace_copy_if
	std::vector<int> ivec8{ 1,2,3,4,5,6,7,8,9,10,11 };
	std::replace_copy_if(ivec8.cbegin(), ivec8.cend(), std::ostream_iterator<int>(cout, ","), [](const int& val) {return val % 2 == 0; }, 0);

	cout << endl;
	//unique_copy
	std::string str = "Hello, here are sometimes   more and     sometimes fewer spaces.";
	std::copy(str.cbegin(), str.cend(), std::ostream_iterator<char>(cout));
	cout << endl;
	std::unique_copy(str.cbegin(), str.cend(), std::ostream_iterator<char>(cout), BothSpace());

	//partition
	std::vector<int> ivec9(10), ivec10(10);
	std::iota(ivec9.begin(), ivec9.end(), 1);
	std::iota(ivec10.begin(), ivec10.end(), 1);
	std::partition(ivec9.begin(), ivec9.end(), [](const int& val) { return val % 3 == 0; });
	std::stable_partition(ivec10.begin(), ivec10.end(), [](const int& val) {return val % 3 == 0; });
	PRINT_ELEMENTS(ivec9, "partition: ");
	PRINT_ELEMENTS(ivec10, "stable_partition: ");

	//partition colllection to to ranges
	std::vector<int> ivec11(10),dest1, dest2;

	std::iota(ivec11.begin(), ivec11.end(), 1);
	std::partition_copy(ivec11.cbegin(), ivec11.cend(), std::back_inserter(dest1), std::back_inserter(dest2), [](const int& val) {return val % 2 == 0; });
	PRINT_ELEMENTS(dest1, "Even: ");
	PRINT_ELEMENTS(dest2, "Odd: ");

	//nth_elements
	std::vector<int> ivec12{ 1,5,3,2,10,3,4,7,5,6,7,3,8,9 };
	std::nth_element(ivec12.begin(), std::find(ivec12.begin(), ivec12.end(), 4), ivec12.end());
	PRINT_ELEMENTS(ivec12, "nth_elements");
}