#pragma once
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <set>

template<typename Container>
void PRINT_ELEMENTS(const Container& c, const std::string& prefix)
{
	std::cout << prefix << std::endl;
	for (auto& i : c)
	{
		std::cout << i << std::endl;
	}
}

class IntSequence
{
private:
	int initValue;
public:
	IntSequence(int val) :initValue(val) {}
	int operator()()
	{
		return initValue++;
	}
};

class MeanValue
{
private:
	long num;
	long sum;
public:
	MeanValue(long num = 0, long sum = 0) :num(num), sum(sum) {}
	void operator()(int val)
	{
		++num;
		sum += val;
	}

	double value()
	{
		return static_cast<double>(sum) / static_cast<double>(num);
	}
};

class Person
{
private:
	std::string name;
public:
	Person(const std::string& name) :name(name) {}
	const std::string& getName() const
	{
		return name;
	}
	void printName() const
	{	
		std::cout << name << std::endl;
	}

	void printNameWithPrefix(const std::string& prefix) const
	{
		std::cout << prefix << ": " << name << std::endl;
	}

	void setName(const std::string& val)
	{
		name = val;
	}
};

struct PersonCompare
{
	bool operator()(const Person& p1, const Person& p2) const
	{
		return p1.getName() < p2.getName();
	}
};

int main()
{
	std::list<int> li;
	std::generate_n(std::back_inserter(li), 10, IntSequence(1));
	PRINT_ELEMENTS(li, "IntSequence: ");

	//for_each return fn
	std::vector<int> ivec{ 1,2,3,4,5,6,7,8 };
	MeanValue fn = std::for_each(ivec.cbegin(), ivec.cend(), MeanValue());
	std::cout << fn.value() << std::endl;

	//binders
	std::vector<int> ivec2{ 1,2,3,4,5,6,7,8 };
	std::transform(
		ivec2.begin(),
		ivec2.end(),
		ivec2.begin(),
		std::bind(
			std::multiplies<int>(),
			2,
			std::bind(std::plus<int>(), std::placeholders::_1, 2)
		)
	);
	PRINT_ELEMENTS(ivec2, "add 2 and multiplies 2 :");

	//call member functions
	std::cout << "call¡¡member functions:¡¡" << std::endl;
	Person p{ "xi" };
	Person p2{ "p2" };
	auto printName = std::bind(&Person::printName, std::placeholders::_1);
	printName(p);
	printName(p2);

	std::set<Person, PersonCompare> people{ Person("p1"),Person("p2"), Person("p3") };
	std::for_each(people.cbegin(), people.cend(), std::bind(&Person::printNameWithPrefix, std::placeholders::_1, "person: "));

	std::for_each(people.begin(), people.end(), std::bind(&Person::setName, std::placeholders::_1, "paul"));

	std::for_each(people.cbegin(), people.cend(), std::bind(&Person::printNameWithPrefix, std::placeholders::_1, "this is : "));
}