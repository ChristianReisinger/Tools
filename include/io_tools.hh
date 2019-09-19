#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <functional>

#ifndef INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_IO_TOOLS_IO_TOOLS_HH_
#define INCLUDE_DE_UNI_FRANKFURT_ITP_REISINGER_TOOLS_IO_TOOLS_IO_TOOLS_HH_

namespace de_uni_frankfurt_itp {
namespace reisinger {
namespace tools {
namespace io_tools {

template<typename T>
void consume_until(std::istream& data, std::function<bool(T)> condition);

std::istream& getline(std::istream& from, std::ostream& to);

std::istream& getline(std::istream& from, std::ostream& to, char delim);

bool file_exists(const std::string& filename);

int parse_int(const std::string& s);

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);

template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V> m);

template<typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p);

std::istream& operator>>(std::istream& from, std::ostream& to);

std::ostream& operator<<(std::ostream& to, std::istream& from);

}
}
}
}

#include <detail/io_tools.tcc>

#endif
