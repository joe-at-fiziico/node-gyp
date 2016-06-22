#include "../include/qos.h"

double Estimate (int points) {
  
   return points * points;
}

/*
  command to build:
  == static library
  gcc -c src/qos.cc -o build/qos.o
  ar rcs build/libqos.a build/qos.o
  
  == shared library
  gcc -c -fPIC -o build/qos.o src/qos.cc
  gcc -shared -fPIC -o build/libqos.so build/qos.o -lc
*/
