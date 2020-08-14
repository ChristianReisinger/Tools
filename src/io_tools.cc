#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

#include <io_tools.hh>

namespace de_uni_frankfurt_itp {
namespace reisinger {
namespace tools {
namespace io_tools {

std::istream& getline(std::istream& from, std::ostream& to) {
	return getline(from, to, from.widen('\n'));
}

std::istream& getline(std::istream& from, std::ostream& to, char delim) {
	std::string str;
	std::getline(from, str, delim);
	to << str;
	return from;
}

bool file_exists(const std::string& filename) {
	std::ifstream ifs(filename);
	return ifs.is_open();
}

int parse_int(const std::string& s) {
	std::istringstream int_iss(s);
	int i;
	int_iss >> i;
	if (int_iss.fail())
		throw std::invalid_argument("string does not represent an int");
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

}
}
}
}
