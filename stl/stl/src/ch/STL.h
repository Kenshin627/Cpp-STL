#pragma once
#include <array>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
	using std::cout, std::endl;
	std::array<int, 5> ia{};
	for (auto& i : ia)
	{
		cout << i << endl;
	}

	std::vector<int> coll = { 2,5,4,1,6,3 };
	auto min = std::min_element(coll.cbegin(), coll.cend());
	auto max = std::max_element(coll.cbegin(), coll.cend());


	std::cout << "min: " << *min << "  " << "max: " << *max << endl;

	std::sort(coll.begin(), coll.end(), std::greater<int>());

	for (auto& i : coll)
	{
		cout << i << endl;
	}
	auto pos3 = std::find(coll.begin(), coll.end(), 3);
	std::reverse(pos3, coll.end());

	for (auto& i : coll)
	{
		cout << i << endl;
	}
}