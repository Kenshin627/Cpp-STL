#pragma once
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <list>
#include <deque>

template<typename T>
void PRINT_ELEMENTS(const T& container, const std::string& prefix)
{
	std::cout << prefix << std::endl;
	for (auto& i : container)
	{
		std::cout << i << std::endl;
	}
}

int main()
{
	//output Iterator
	//1. ostream_iterator
	std::vector <std::string > vec{ "h", "e", "l", "l", "o" };
	std::copy(vec.cbegin(), vec.cend(), std::ostream_iterator<std::string>(std::cout, ","));

	//2. inserter
	std::list<std::string> ss;
	std::copy(vec.cbegin(), vec.cend(), std::inserter(ss, ss.begin()));
	std::copy(ss.cbegin(), ss.cend(), std::ostream_iterator<std::string>(std::cout, " "));

	//input Iterator
	//std::list<std::string> li;
	//std::istream_iterator<std::string> begin (std::cin);
	//std::istream_iterator<std::string> eos;
	//std::copy(begin, eos, std::inserter(li, li.begin()));
	//std::copy(li.cbegin(), li.cend(), std::ostream_iterator<std::string>(std::cout));

	//problem
	std::deque<int> ivec{ 1,5,4,3,10 };
	//std::sort(++ivec.begin(), ivec.end()); //ERROR
	//std::copy(ivec.cbegin(), ivec.cend(), std::ostream_iterator<int>(std::cout));

	//iter_swap
	std::vector<int> ivec1{ 1,2,3,4,5 };
	PRINT_ELEMENTS(ivec1, "first: ");

	std::iter_swap(ivec1.begin(), std::next(ivec1.begin(), 2));
	PRINT_ELEMENTS(ivec1, "second: ");

	std::iter_swap(ivec1.begin(), std::prev(ivec1.end()));
	PRINT_ELEMENTS(ivec1, "third: ");

	//reverse_iterator
	// convert normal iter to reverse
	std::vector<int> ivec2{ 1,2,3,4,5,6,7,8,9 };
	decltype(ivec2)::const_iterator pos = std::find(ivec2.cbegin(), ivec2.cend(), 6);
	std::cout << *pos << std::endl;

	//convert to base
	decltype(ivec2)::const_reverse_iterator reversed(pos);
	std::cout << *reversed << std::endl;
	std::cout << *reversed.base() << std::endl;

	//insertor_iterater
	//1. back_inserter
	std::set<int> ss1{ 4,6,4,3,5,7,8,1,2,5 };
	std::vector<int> ivec3;
	std::vector<int> ivec4;
	std::copy(ss1.crbegin(), ss1.crend(), std::back_inserter(ivec3));
	PRINT_ELEMENTS(ivec3, "back_inserter");

	std::back_insert_iterator bi = std::back_inserter(ivec4);
	bi = 4;
	bi = 5;
	bi = 6;
	PRINT_ELEMENTS(ivec4, "assegment to back_inserter_iterator");
}
