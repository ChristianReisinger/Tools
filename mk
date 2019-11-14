#!/bin/bash

(cd build

if [ "${1,,}" == build ]; then
	cmake $cmake_defines ..
elif [ "$1" == clear ]; then
	rm -rf ../build/* ../bin/* ../lib/*
elif [ "$1" == clean ]; then
	make clean
	rm -rf ../bin/* ../lib/*
elif [ "$1" == "" ]; then
	make install
else
	echo "Invalid target '$1'"
fi

)