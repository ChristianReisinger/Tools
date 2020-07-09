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

std::filesystem::path next_unused_filepath(const std::filesystem::path& start_path, const std::string& suffix_sep) {
	if (!start_path.has_filename()) throw std::invalid_argument("not a filepath");

	const auto parent_dir = start_path.parent_path();
	const auto stem = start_path.stem();
	const auto ext = start_path.extension();

	auto next_filename = start_path.filename();
	for (int counter = 1; file_exists(parent_dir / next_filename); ++counter) {
		next_filename = stem;
		next_filename += suffix_sep + std::to_string(counter);
		next_filename += ext;
	}

	return parent_dir / next_filename;
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
