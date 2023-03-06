#pragma once
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

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

template <typename Container>
bool replace_key(Container& c, const typename Container::key_type& old_key, const typename Container::key_type& new_key)
{
	auto it = c.find(old_key);
	
	if (it != c.cend())
	{
		auto val = it->second;
		c.erase(it->first);
		c.insert({ new_key, val });
		return true;
	}
	else {
		cout << "not found key:" << old_key << endl;
		return false;
	}
}

int main()
{
	std::map<int, std::string> m{ {1,"1"}, {2,"2"},{3,"3"},{4,"4"} };
	replace_key(m, 1, 10);
	for (auto& i : m)
	{
		cout << "key: " << i.first << "||" << "value: " << i.second << endl;
	}

	//for_each
	std::map<int, std::string> m1{ {1,"1"}, {2,"2"},{3,"3"},{4,"4"} };
	std::for_each(m1.cbegin(), m1.cend(), [](decltype(m1)::value_type v) {
		cout << "key: " << v.first << "||" << "value: " << v.second << endl;
		});

	//erase
	std::map<int, int> m3{ {1,1},{2,2},{3,3},{4,4},{5,3} };
	int desVal = 3;
	typedef decltype(m3)::iterator Iter;
	Iter it;
	for (it = m3.begin(); it != m3.end();)
	{
		if (it->second == desVal)
		{
			it = m3.erase(it);
		}
		else {
			++it;
		}
	}

	cout << "m3: " << endl;
	for (auto& i : m3)
	{
		cout << "key: " << i.first << "||" << "value: " << i.second << endl;
	}
}