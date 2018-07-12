#include <iostream>
#include <functional>
#include <io_tools.hh>

template<typename T>
void io_tools::consume_until(std::istream& data, std::function<bool(T)> condition) {
	T consumed;
	do {
		data >> consumed;
	} while (!condition(consumed));
}
