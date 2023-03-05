#pragma once
#include <map>
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
}