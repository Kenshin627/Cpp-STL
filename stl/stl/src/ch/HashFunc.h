#pragma once
#include <functional>

template<typename T>
inline void hash_combine(size_t& seed, const T& val)
{
	seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<typename T>
inline void hash_Val(size_t& seed, const T& val)
{
	hash_combine(seed, val);
}

template<typename T, typename...Args>
inline void hash_Val(size_t& seed, const T& val, const Args&...args)
{
	hash_combine(seed, val);
	hash_Val(seed, args...);
}


template<typename...Args>
inline size_t hash_Val(const Args&...args)
{
	size_t seed = 0;
	hash_Val(seed, args...);
	return seed;
}
