#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>

using std::cout, std::endl;

#pragma region PRINT
void print() {}

template<typename T, typename...Args>
void print(const T& t, const Args&...args)
{
	cout << t << endl;
	print(args...);
}
#pragma endregion

#pragma region PRINTF
void printfs(const char* s)
{
	while (*s)
	{
		if (*s == '%' && *(++s) != '%')
		{
			throw std::runtime_error("invalid formant string");
		}
		std::cout << *s++;
	}
}

template<typename T, typename...Args>
void printfs(const char* s, const T& val, const Args&... args)
{
	while (*s)
	{
		if (*s == '%' && *(++s) != '%')
		{
			cout << val;
			printfs(++s, args...);
			return;
		}
		cout << *s++;
	}
}
#pragma endregion

#pragma region MAXIMUM
int maximum(int n)
{
	return n;
}

template<typename...Args>
int maximum(int n, const Args&...args)
{
	return std::max(n, maximum(args...));
}
#pragma endregion

#pragma region PRINT_TUPLE

template<int IDX, int MAX, typename...Args>
struct PRINT_TUPLE {
	static void print(std::ostream& out, const std::tuple<Args...>& t)
	{
		cout << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
		PRINT_TUPLE<IDX+1, MAX, Args...>::print(out, t);
	}
};


template<int MAX, typename...Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
	static void print(std::ostream& out, const std::tuple<Args...>& t) {}
};


template<typename...Args>
std::ostream& operator<<(std::ostream& out, const std::tuple<Args...>& t)
{
	cout << "[";
	PRINT_TUPLE<0, sizeof...(Args), Args...>::print(out, t);
	return cout << "]";
}

#pragma endregion

#pragma region TUPLE

template<typename...Values> class tuple;
template<> class tuple<> {};
template<typename Head, typename...Tails>
class tuple<Head, Tails...>:private tuple<Tails...>
{
	typedef tuple<Tails...> base;
protected:
	Head _head;
public:
	tuple() = default;
	tuple(Head head, Tails...tails) :_head(head), base(tails...) {}
	Head head() const { return _head; };
	base& tails() const { return *this; };
	auto get(int idx) const
	{
		return idx == 0 ? _head ? : tails().get(--idx);
	}
};
#pragma endregion

#pragma region PRINT_CUSTOM_TUPLE

template<typename...Args>
std::ostream& operator<<(std::ostream& out, const tuple<Args...>& t)
{
	out << "[";
	PRINT_CUSTOM_TUPLE<0, sizeof...(Args), Args...>::print(out, t);
	return out << "]";
}

template<int IDX, int MAX, typename...Args>
struct PRINT_CUSTOM_TUPLE
{
	static void print(std::ostream& out, const tuple<Args...>& t)
	{
		out << t.get(IDX) << (IDX + 1 == MAX ? "" : ",");
		PRINT_CUSTOM_TUPLE<IDX + 1, MAX, Args...>::print(out, t);
	}
};

template<int MAX, typename...Args>
struct PRINT_CUSTOM_TUPLE<MAX, MAX, Args...>
{
	static void print(std::ostream& out, const tuple<Args...>& t)
	{
		
	}
};

#pragma endregion


int main()
{
	//print
	print(1, "hello world", 'c');

	//printf
	printfs("%d%d%dasdf123 hello world", 11, 22, 'c');

	//print_tuple
	auto t = std::tuple{ 1,"hello",'c', false };
	cout << t << endl;

	//tuple
	tuple<int, std::string, char> customTuple{ 1, "tt", 'c' };
	cout << customTuple;
}