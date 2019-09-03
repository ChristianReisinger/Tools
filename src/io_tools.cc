#include <iostream>
#include <string>
#include <sstream>

#include <io_tools.hh>

std::istream& io_tools::getline_iss(std::istream& from, std::istringstream& to) {
	return getline_iss(from, to, from.widen('\n'));
}

std::istream& io_tools::getline_iss(std::istream& from, std::istringstream& to, char delim) {
	std::string str;
	std::getline(from, str, delim);
	to = std::istringstream(str);
	return from;
}

std::istringstream& operator>>(std::istringstream& from, std::istringstream& to) {
	std::string str;
	from >> str;
	to = std::istringstream(str);
	return from;
}
