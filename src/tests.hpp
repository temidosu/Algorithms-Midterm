#include <chrono>
// #include <fstream>
#include <iomanip> // std::setprecision()
#include <iostream>
#include <vector>

#include <folly/FBString.h>
#include <string>

#pragma once

class tests {
	public:
	tests();

	private:
	// std::ofstream outputStream;

	std::chrono::_V2::system_clock::time_point fbstart;
	std::chrono::_V2::system_clock::time_point fbend;

	std::chrono::_V2::system_clock::time_point libstdstart;
	std::chrono::_V2::system_clock::time_point libstdend;

	void defaultConstruction();
	
	void smallString();
	void mediumString();
	void longString();

	void smallFind();
	void mediumFind();
	void longFind();


	void outputResultsofRun();
};