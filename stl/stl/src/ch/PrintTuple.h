#pragma once
#include <tuple>
#include <iostream>


/*´òÓ¡tupleÊ¾Àý*/
template<int IDX, int MAX, typename...Args>
struct PRINT_TUPLE 
{
	static void print(std::ostream& out, const std::tuple<Args...>& t)
	{
		out << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
		PRINT_TUPLE<IDX + 1, MAX, Args...>::print(out, t);
	}
};

template<int MAX, typename...Args>
struct PRINT_TUPLE<MAX, MAX, Args...>
{
	static void print(std::ostream& out, const std::tuple<Args...>& t)
	{
	
	}
};

template<typename...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& t)
{
	out << "[";
	PRINT_TUPLE<0, sizeof...(Args), Args...>::print(out, t);
	return out << "]";
}

int main()
{
	auto t = std::make_tuple(12, 1.0f, 3.0, "hola");
	std::cout << t << std::endl;
}