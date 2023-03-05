#pragma once
#include <forward_list>
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

template<typename InputIterator, typename T>
InputIterator& find_before(InputIterator& before_first, InputIterator& last, const T& val)
{
	if (before_first == last)
	{
		return before_first;
	}
	InputIterator next(before_first);
	++next;
	while (next != last && *next != val)
	{
		++next;
		++before_first;
	}
	return before_first;
}

template<typename InputIterator, typename Pred>
InputIterator& find_before_If(InputIterator before_first, InputIterator last, Pred pred)
{
	if (before_first == last)
	{
		return before_first;
	}
	InputIterator next(before_first);
	++next;
	while (next != last && !pred(*next))
	{
		++next;
		++before_first;
	}
	return before_first;
}

int main()
{
	std::forward_list<int> it{ 1,2,3,4,5,6,7,8,9 };
	auto posBefore = find_before_If(it.before_begin(), it.end(), [](int val) { return val % 2 == 0; });
}