#include <iostream>
#include <vector>
#include <utility>
#include <functional>

#include <io_tools.hh>

template<typename T>
void io_tools::consume_until(std::istream& data, std::function<bool(T)> condition) {
	T consumed;
	do {
		data >> consumed;
	} while (!condition(consumed));
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
	os << "{ ";
	bool first = true;
	for (const T& elem : v) {
		if (!first)
			os << ", ";
		os << elem;
		first = false;
	}
	os << " }";
	return os;
}

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
	os << "{ " << p.first << ", " << p.second << " }";
	return os;
}
