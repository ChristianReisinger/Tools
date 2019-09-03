#include <iostream>
#include <sstream>
#include <functional>

#ifndef INCLUDE_IO_TOOLS_HH_
#define INCLUDE_IO_TOOLS_HH_

namespace io_tools {

template<typename T>
void consume_until(std::istream& data, std::function<bool(T)> condition);

std::istream& getline_iss(std::istream& from, std::istringstream& to);

std::istream& getline_iss(std::istream& from, std::istringstream& to, char delim);

}

std::istringstream& operator>>(std::istringstream& from, std::istringstream& to);

#include <detail/io_tools.tcc>

#endif /* INCLUDE_IO_TOOLS_HH_ */
