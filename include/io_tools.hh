#include <iostream>
#include <functional>

#ifndef INCLUDE_IO_TOOLS_HH_
#define INCLUDE_IO_TOOLS_HH_

namespace io_tools {

template<typename T>
void consume_until(std::istream& data, std::function<bool(T)> condition);

}

#include <detail/io_tools.tcc>

#endif /* INCLUDE_IO_TOOLS_HH_ */
