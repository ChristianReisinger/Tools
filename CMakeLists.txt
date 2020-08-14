cmake_minimum_required(VERSION 3.10)
project(tools)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11")

include_directories(include)

add_library(helper_functions SHARED src/helper_functions.cc)
add_library(io_tools SHARED src/io_tools.cc)
add_library(linalg_io SHARED src/linalg_io.cc)
add_library(math_functions SHARED src/math_functions.cc)
add_library(tools SHARED src/Stopwatch.cc)
add_executable(regex_match_multiline src/regex_match_multiline.cc)
add_executable(toranges src/toranges.cc)

if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9.1)
	set(CXX_FILESYSTEM_LIBRARIES "stdc++fs")
	target_link_libraries(io_tools PUBLIC "${CXX_FILESYSTEM_LIBRARIES}")
endif()

install(TARGETS
	helper_functions
	io_tools
	linalg_io
	math_functions
	tools
DESTINATION "${CMAKE_SOURCE_DIR}/lib")
install(TARGETS regex_match_multiline toranges DESTINATION "${CMAKE_SOURCE_DIR}/bin")
