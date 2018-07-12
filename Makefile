CXX=g++
CXXFLAGS=-std=c++11
INCLUDE=-I"include"

SRC_DIR=src/
BUILD_DIR=lib/
NAMES=linalg_io

OBJS=${NAMES:%=${BUILD_DIR}/lib%.o}

all: ${OBJS}

${BUILD_DIR}/lib%.o: ${SRC_DIR}/%.cc
	${CXX} ${CXXFLAGS} -c -o $@ $< ${INCLUDE}
	
clean:
	rm -f ${BUILD_DIR}/*
