#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "HashFunc.h"

using std::cout, std::endl;

class Customer
{
	friend std::ostream& operator<<(std::ostream& out, const Customer& c);
	friend class CustomerHash;
public:
	Customer(const std::string& f = "", const std::string& m = "", const std::string& l = "") :fname(f), mname(m), lname(l) {}
	bool operator==(const Customer& rhs) const
	{
		return fname == rhs.fname &&
			mname == rhs.mname &&
			lname == rhs.lname;
	}
private:
	std::string fname;
	std::string mname;
	std::string lname;
};

std::ostream& operator<<(std::ostream& out, const Customer& c)
{
	out << c.fname << ' ' << c.mname << ' ' << c.lname;
	return out;
}

struct CustomerHash
{
	size_t operator()(const Customer& c) const
	{
		return hash_Val(c.fname, c.mname, c.lname);
	}
};

int main()
{
	std::unordered_map<Customer, int, CustomerHash> customers;
	customers.max_load_factor(1);
	customers.insert({ Customer("1", "2", "3"), 12 });
	customers.insert({ Customer("12", "2da", "3"), 12 });
	customers.insert({ Customer("13", "2cc", "3"), 12 });
	customers.insert({ Customer("14", "2", "3"), 12 });
	customers.insert({ Customer("1", "3", "3"), 12 });
	customers.insert({ Customer("21", "d", "3"), 12 });
	customers.insert({ Customer("33", "a", "3"), 12 });
	customers.insert({ Customer("41", "c", "3"), 12 });
	customers.insert({ Customer("1", "2", "311"), 12 });
	customers.insert({ Customer("2", "3", "33"), 12 });
	customers.insert({ Customer("3", "4", "13"), 12 });
	customers.insert({ Customer("4", "5", "vv"), 12 });

	size_t bucketCount = customers.bucket_count();
	cout << "bucket count: " << bucketCount << endl;
	cout << "element count: " << customers.size() << endl;
	cout << "load factor: " << customers.load_factor() << endl;
	for (size_t i = 0; i < bucketCount; i++)
	{
		cout << "buckets # " << i << " elements : " << customers.bucket_size(i) << endl;
	}

	std::for_each(customers.cbegin(11), customers.cend(11), [](const decltype(customers)::value_type& it) {
		cout << "key: " << it.first << "||" << "val: " << it.second << endl;
	});
}