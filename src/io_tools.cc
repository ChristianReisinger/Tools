#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

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

bool io_tools::file_exists(const std::string& filename) {
	std::ifstream ifs(filename);
	return ifs.is_open();
}

int io_tools::parse_int(const std::string& s) {
	std::istringstream int_iss(s);
	int i;
	int_iss >> i;
	if (int_iss.fail())
		throw std::invalid_argument("parse_int: string does not represent an int");
	return i;
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
