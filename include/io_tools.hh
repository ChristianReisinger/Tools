#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>

#ifndef INCLUDE_IO_TOOLS_HH_
#define INCLUDE_IO_TOOLS_HH_

namespace io_tools {

template<typename T>
void consume_until(std::istream& data, std::function<bool(T)> condition);

std::istream& getline(std::istream& from, std::ostream& to);

std::istream& getline(std::istream& from, std::ostream& to, char delim);

bool file_exists(const std::string& filename);

int parse_int(const std::string& s);

}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p);

std::istream& operator>>(std::istream& from, std::ostream& to);

std::ostream& operator<<(std::ostream& to, std::istream& from);

#include <detail/io_tools.tcc>

#endif /* INCLUDE_IO_TOOLS_HH_ */
