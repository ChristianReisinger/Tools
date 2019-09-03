CXX=g++
CXXFLAGS=-std=c++11
INCLUDE=-I"include"

SRC_DIR=src/
BUILD_DIR=lib/
BIN_DIR=bin/
LIB_NAMES=linalg_io helper_functions math_functions io_tools
BIN_NAMES=toranges regex_match_multiline

OBJS=${LIB_NAMES:%=${BUILD_DIR}/lib%.so}
BINS=${BIN_NAMES:%=${BIN_DIR}/%}

all: ${OBJS} ${BINS}

${BUILD_DIR}/lib%.so: ${SRC_DIR}/%.cc
	${CXX} ${CXXFLAGS} -c -o $@ $< ${INCLUDE}
	
${BINS}: ${BIN_DIR}/%: ${SRC_DIR}/%.cc
	${CXX} ${CXXFLAGS} -o $@ $^
	
clean:
	rm -f ${BUILD_DIR}/* ${BIN_DIR}/*
