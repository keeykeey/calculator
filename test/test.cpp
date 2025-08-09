// g++ -o test test.cc -lCppUTest
#include "CppUTest/CommandLineTestRunner.h"

int main(int argc, char **argv){
    return CommandLineTestRunner::RunAllTests(argc, argv);
}