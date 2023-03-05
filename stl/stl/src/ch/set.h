#pragma once
#include <set>
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

class RuntimeCmp
{
public:
	enum cmp_mode
	{
		normal,
		reverse
	};
	RuntimeCmp(cmp_mode mode = RuntimeCmp::normal) :mode(mode) {}
	template<typename T>
	bool operator()(const T& t1, const T& t2) const
	{
		return mode == normal ? t1 < t2 :
			t1 > t2;
	}
	bool operator==(const RuntimeCmp& rhs) const
	{
		return mode == rhs.mode;
	}
private:
	cmp_mode mode;
};

int main()
{
	//lower_bound upper_bound
	std::set<int> set1{ 1,2,3,4,5 };
	cout << "lower_bound(3): " << *set1.lower_bound(3) << endl;
	cout << "upper_bound(3): " << *set1.upper_bound(3) << endl;
	cout << "equal_range(3): " << *set1.equal_range(3).first << * set1.equal_range(3).second << endl;

	//insert
	std::set<double> set2{ 3.3 };
	if (set2.insert(3.3).second)
	{
		cout << "3.3 inserted" << endl;
	}
	else {
		cout << "3.3 already exists: " << endl;
	}

	//insert with addition position it
	std::set<int> set3{ 1,2,3,4,5 };
	auto ret = set3.insert(set3.begin(), 3);
	cout << *ret << endl;

	//specifying the sorting criterion at runtime
	typedef std::set<int, RuntimeCmp> IntSet;
	IntSet coll1 = { 4,7,5,1,6,2,5 };
	PRINT_ELEMENTS(coll1, "coll1: "); //1 2 4 5 6 7

	RuntimeCmp reverse_order(RuntimeCmp::reverse);
	IntSet coll2(reverse_order);
	coll2 = { 4,7,5,1,6,2,5 };
	PRINT_ELEMENTS(coll2, "coll2: ");// 7 6 5 4 2 1

	coll1 = coll2;
	coll1.insert(3); //7 6 5 4 3 2 1
	PRINT_ELEMENTS(coll1, "coll1: ");

	if (coll1.value_comp() == coll2.value_comp())
	{
		cout << "coll1 and coll2 have the same sorting criterion" //¡Ì
			<< endl;
	}
	else {
		cout << "coll1 and coll2 have a different sorting criterion"
			<< endl;
	}
}