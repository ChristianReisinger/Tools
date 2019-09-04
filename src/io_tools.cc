#include <iostream>
#include <string>

#include <io_tools.hh>

std::istream& io_tools::getline(std::istream& from, std::ostream& to) {
	return getline(from, to, from.widen('\n'));
}

std::istream& io_tools::getline(std::istream& from, std::ostream& to, char delim) {
	std::string str;
	std::getline(from, str, delim);
	to << str;
	return from;
}

std::istream& operator>>(std::istream& from, std::ostream& to) {
	std::string str;
	from >> str;
	to << str;
	return from;
}

std::ostream& operator<<(std::ostream& to, std::istream& from) {
	std::string str;
	from >> str;
	to << str;
	return to;
}
