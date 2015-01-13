#!/bin/bash

#TODO: write Makefile

CPPFLAGS="-I ../include -I mocks"
CXXFLAGS="-Wall -Wextra -Werror -std=c++11 -march=native -O0 -ggdb3 -fno-inline -c"
OBJDIR="objs"

mkdir -p $OBJDIR
g++ $CPPFLAGS $CXXFLAGS main.cpp -o $OBJDIR/main.o
g++ $CPPFLAGS $CXXFLAGS LinkTestSuite.cpp -o $OBJDIR/LinkTestSuite.o
g++ $CPPFLAGS $CXXFLAGS ../src/Link.cpp -o $OBJDIR/Link.o
g++ -o tests $OBJDIR/main.o $OBJDIR/LinkTestSuite.o $OBJDIR/Link.o -L /usr/src/gtest -L /usr/src/gmock -lgtest -lgmock -lpthread
