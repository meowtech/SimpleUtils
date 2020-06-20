#include "StopWatch.hh"
#include <iostream>

using namespace simple_utils;

int main() {
	StopWatch watch;
	std::cout << watch.Tok() << "ms" << std::endl;
	return 0;
}