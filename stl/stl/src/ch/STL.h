#pragma once
#include <array>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

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

	std::vector<int> ivec{ 1,2,3,4,5 };
	std::vector<int> ivec2;
	ivec2.resize(ivec.size());
	std::copy(ivec.begin(), ivec.end(), ivec2.begin());
	std::cout << "ivec2:" << std::endl;
	for (auto& i : ivec2)
	{
		std::cout << i << std::endl;
	}

	std::vector<int> ivec3;
	std::insert_iterator<std::vector<int>> inserter(ivec3, ivec3.begin());
	std::copy(ivec.cbegin(), ivec.cend(), inserter);

	std::cout << "ivec3:" << std::endl;
	for (auto& i : ivec3)
	{
		std::cout << i << std::endl;
	}

	std::vector<int> ivec0{ 1,2,3 };
	//back_insert
	std::vector<int> ivec4;
	std::copy(ivec0.cbegin(), ivec0.cend(), std::back_inserter(ivec4));
	std::cout << "vec4" << endl;
	for (auto& i : ivec4)
	{
		std::cout << i << std::endl;//1 2 3
	}

	//front_insert
	std::deque<int> ivec5;
	std::copy(ivec0.cbegin(), ivec0.cend(), std::front_inserter(ivec5));
	std::cout << "vec5" << endl;
	for (auto& i : ivec5)
	{
		std::cout << i << std::endl;//3 2 1
	}

	//insert
	std::vector<int> ivec6;
	std::copy(ivec0.cbegin(), ivec0.cend(), std::inserter(ivec6, ivec6.begin()));
	std::cout << "vec6" << endl;
	for (auto& i : ivec6)
	{
		std::cout << i << std::endl;//1 2 3
	}

	//istream_iterator ostream_iterator
	std::vector<std::string> svec;
	std::istream_iterator<std::string> it(std::cin);
	std::istream_iterator<std::string> eos;
	std::copy(it, eos, std::inserter(svec, svec.begin()));

	std::sort(svec.begin(), svec.end());


	std::ostream_iterator<std::string> ot(std::cout);
	std::copy(svec.cbegin(), svec.cend(), ot);
}