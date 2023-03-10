#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <map>

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

class GeneraterNums
{
private:
	int initialVal;
public:
	GeneraterNums(int val) :initialVal(val) {}
	int operator()()
	{
		return initialVal++;
	}
};
template<typename T>
class AddValue
{
private:
	T value;
public:
	AddValue(const T& val) :value(val) {}
	void operator()(T& val)
	{
		val += value;
	}
};

class MeanValue
{
private:
	long num;
	long sum;
public:
	MeanValue() = default;
	void operator()(int val)
	{
		++num;
		sum += val;
	}
	operator double()
	{
		return sum / num;
	}
};

class CheckEven
{
public:
	bool operator()(int val, bool even)
	{
		if (even)
		{
			return val % 2 == 0;
		}
		else {
			return val % 2 != 0;
		}
	}
};


int main()
{
	//copy_backward
	std::vector<int> vec1;
	for (size_t i = 1; i <= 5; i++)
	{
		vec1.push_back(i * 10);		
	}
	vec1.resize(vec1.size() + 3);
	std::copy_backward(vec1.cbegin(), vec1.cbegin() + 5, vec1.end());
	PRINT_ELEMENTS(vec1, "copy: ");

	//replace_copy
	std::vector<int> vec2{ 1,2,3,4,5 };
	std::vector<int> vec3;
	std::replace_copy(vec2.cbegin(), vec2.cend(), std::back_inserter(vec3), 3, 30);	
	PRINT_ELEMENTS(vec3, "replace_copy: ");

	//generate
	std::vector<int> vec4(5);
	std::generate(vec4.begin(), vec4.end(), GeneraterNums(10));
	PRINT_ELEMENTS(vec4, "generate: ");

	//generate n
	int size = 20;
	std::vector<int> vec5(size);
	std::generate_n(vec5.begin(), size, GeneraterNums(1));
	PRINT_ELEMENTS(vec5, "generate n: ");

	//remove_if
	std::vector<int> vec6{ 1,2,3,4,5,6,7,8,9 };
	std::remove_if(vec6.begin(), vec6.end(), [](int val) { return val <= 3; });
	PRINT_ELEMENTS(vec6, "remove_if");

	//remove_copy_if
	std::vector<int> vec7{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> vec8(9);
	std::remove_copy_if(vec7.cbegin(), vec7.cend(), vec8.begin(), [](int val) { return val <= 3; });
	PRINT_ELEMENTS(vec8, "remove_copy_if: ");

	//unique
	std::vector<int> vec9{ 10,20,20,20,30,30,20,20,10 };
	auto endIt = std::unique(vec9.begin(), vec9.end());
	PRINT_ELEMENTS(vec9, "unique: ");

	//rotate
	std::vector<int> vec10{ 1,2,3,4,5,6,7,8,9,10 };
	std::rotate(vec10.begin(), vec10.begin() + 4, vec10.end());
	PRINT_ELEMENTS(vec10, "roate: ");

	//for_each modify
	std::vector<int> vec11{ 1,2,3,4,5,6,7,8,9 };
	std::for_each(vec11.begin(), vec11.end(), [](int& val) { val += 10; });
	PRINT_ELEMENTS(vec11, "for_each modify: ");

	//for_each modify function object
	std::vector<int> vec12{ 1,2,3,4,5,6,7,8,9 };
	std::for_each(vec12.begin(), vec12.end(), AddValue<int>(10));
	PRINT_ELEMENTS(vec12, "for_each function object: ");

	//for_each return value->operation
	auto res = std::for_each(vec12.cbegin(), vec12.cend(), MeanValue());
	std::cout << "meanValue of vec12 elements is : " << res << endl;

	//find
	std::vector<int> vec13{ 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9 };
	auto pos1 = std::find(vec13.cbegin(), vec13.cend(), 4);
	if (pos1 != vec13.cend())
	{
		auto pos2 = std::find(++pos1, vec13.cend(), 4);
		if (pos1 != vec13.cend() && pos2 != vec13.cend())
		{
			std::copy(--pos1, ++pos2, std::ostream_iterator<int>(cout, ","));
			cout << endl;
		}
	}

	//search_n
	std::vector<int> vec14{ 1,2,2,2,3,3,4,4,4,5,6,7 };
	auto pos = std::search_n(vec14.cbegin(), vec14.cend(), 4, 2);
	if (pos != vec14.cend())
	{
		cout << *pos << endl;
	}
	else {
		cout << "not found" << endl;
	}

	//search
	std::vector<int> vec15{ 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9 };
	std::vector<int> vec16{ 2,3,4,5 };
	decltype(vec15)::const_iterator pos5 = std::search(vec15.cbegin(), vec15.cend(), vec16.cbegin(), vec16.cend());

	//search with function object
	std::vector<int> vec17{ 1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9 };
	bool checkArgs[3] = { true, false, true };
	decltype(vec17)::const_iterator pos4 = std::search(vec17.cbegin(), vec17.cend(), checkArgs, checkArgs + 3, CheckEven());
	
	//adjacent_find
	std::vector<int> vec18{ 1,3,2,4,5,5,0 };
	auto pos3 = std::adjacent_find(vec18.cbegin(), vec18.cend());
	if (pos3 != vec18.cend())
	{
		cout << *pos3 << endl;
	}

	//adjacent_find with function object
	auto pos6 = std::adjacent_find(vec18.cbegin(), vec18.cend(), [](int val1, int val2) { return val1 * 2 == val2; });
	if (pos6 != vec18.cend())
	{
		cout << *pos6 << endl;
	}

	//equal
	std::vector<int> vec19{ 1,2,3,4,5,6 };
	std::vector<int> vec20{ 3,4,5,6,7,8 };
	bool ret = std::equal(vec19.cbegin(), vec19.cend(), vec20.cbegin(), [](int val1, int val2) { return val1 % 2 == val2 % 2; });
	cout << "vec19 an vec20 is " << (ret ? "equal" : "not equal") << endl;

	//move
	std::vector<int> vec21{ 1,2,3 };
	std::vector<int> vec22;

	std::move(vec21.begin(), vec21.end(), std::back_inserter(vec22));
	PRINT_ELEMENTS(vec22, "vec22: ");
	PRINT_ELEMENTS(vec21, "vec21: ");
}