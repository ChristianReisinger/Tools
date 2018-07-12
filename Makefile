CXX=g++
CXXFLAGS=-std=c++11
INCLUDE=-I"include"

SRC_DIR=src/
BUILD_DIR=lib/
NAMES=linalg_io

OBJS=${NAMES:%=${BUILD_DIR}/lib%.so}

all: ${OBJS}

${BUILD_DIR}/lib%.so: ${SRC_DIR}/%.cc
	${CXX} ${CXXFLAGS} -c -o $@ $< ${INCLUDE}
	
clean:
	rm -f ${BUILD_DIR}/*
