#pragma once
#include <array>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

template<typename T>
void PRINT_ELEMENTS(const T& c, const std::string& sepelator)
{
	std::cout << sepelator << std::endl;

	for (auto& i : c)
	{
		std::cout << i << std::endl;
	}
}

template<size_t t>
void addN(int& n)
{
	n += t;
}


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
	//std::vector<std::string> svec;
	//std::istream_iterator<std::string> it(std::cin);
	//std::istream_iterator<std::string> eos;
	//std::copy(it, eos, std::inserter(svec, svec.begin()));

	//std::sort(svec.begin(), svec.end());


	//std::ostream_iterator<std::string> ot(std::cout);
	//std::copy(svec.cbegin(), svec.cend(), ot);

	//user-defined functions
	std::list<int> il;
	for (size_t i = 0; i < 7; i++)
	{
		il.push_front(i);
		il.push_back(i);
	}
	PRINT_ELEMENTS(il, "all elements:");

	//remove
	std::list<int> il1;
	for (size_t i = 1; i <= 6; i++)
	{
		il1.push_back(i);
		il1.push_front(i);
	}

	auto end = std::remove(il1.begin(), il1.end(), 3);
	std::list<int>::const_iterator it;
	for ( it = il1.cbegin(); it != end; ++it)
	{
		std::cout << *it << std::endl;
	}

	std::for_each(il1.cbegin(), il1.cend(), [](int i) { std::cout << i << std::endl; });

	//transform
	std::vector<int> iivec {1, 2, 3, 4, 5};
	std::vector<int> iivec1;
	std::transform(iivec.cbegin(), iivec.cend(), std::back_inserter(iivec1), [](int i) { return i * i; });
	PRINT_ELEMENTS(iivec1, "transform:");

	std::vector<int> iivec2{ 1,2,3,4,5 };
	//origin function

	//function object

}