#include "tests.hpp"

tests::tests(const char *outputFileName) {
	outputStream.open(outputFileName);
	outputStream << "Folly String(seconds)\tlibc String(seconds)"
				 << "\n";

	smallString();
}

void tests::smallString() {
	// Fb string has 3 tiered storage
	fbstart = std::chrono::high_resolution_clock::now();
	folly::fbstring fbstring = "abdefg";
	fbend = std::chrono::high_resolution_clock::now();

	libcstart = std::chrono::high_resolution_clock::now();
	std::string std_string = "abdefg";
	libcend = std::chrono::high_resolution_clock::now();

	outputResultsofRun();
}

void tests::outputResultsofRun() {
	std::chrono::duration<double> follyDuration = fbend - fbstart;
	std::chrono::duration<double> libcDuration = libcend - libcstart;

	std::cout << std::fixed << std::setprecision(9) << std::showpoint;

	std::cout << "folly took " << follyDuration.count() << " sec for small string. libc took "
			  << libcDuration.count() << " sec for small string" << std::endl;

	outputStream << std::fixed << std::setprecision(9);
	outputStream << follyDuration.count() << "\t\t\t\t" << libcDuration.count() << "\n";
}