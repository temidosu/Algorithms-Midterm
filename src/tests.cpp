#include "tests.hpp"

tests::tests(const char *outputFileName) {
	outputStream.open(outputFileName);
	outputStream << "Folly String(seconds)\tlibc String(seconds)"
				 << "\n";

	smallString();
	mediumString();
	longString();
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

void tests::mediumString() {
	// Fb string has 3 tiered storage
	fbstart = std::chrono::high_resolution_clock::now();
	folly::fbstring fbstring = "C6A4bHsmu8BWJrBqBbNPMhy7AVEw88EVGJICwZQ0WtHfpvsPcBkRYCPRAd8k8HoYu1yWKINaR152lW93KVW7ORAZLjocDuvFz3WFFpJzoosx6JHfCvLotpTMPEc5884yhE7C1HhqdmD29TgrOOvkw5Np51SBS0Sg4nOud74Ga6e9Uu9RaU0X2VRl8aC4jWUOM2YNoIvjeav8Pkfvhk0glP80jXDYaJwLmcpV8fuTza2dkrhzuvX1u5UeG4";
	fbend = std::chrono::high_resolution_clock::now();

	libcstart = std::chrono::high_resolution_clock::now();
	std::string std_string = "C6A4bHsmu8BWJrBqBbNPMhy7AVEw88EVGJICwZQ0WtHfpvsPcBkRYCPRAd8k8HoYu1yWKINaR152lW93KVW7ORAZLjocDuvFz3WFFpJzoosx6JHfCvLotpTMPEc5884yhE7C1HhqdmD29TgrOOvkw5Np51SBS0Sg4nOud74Ga6e9Uu9RaU0X2VRl8aC4jWUOM2YNoIvjeav8Pkfvhk0glP80jXDYaJwLmcpV8fuTza2dkrhzuvX1u5UeG4";
	libcend = std::chrono::high_resolution_clock::now();

	outputResultsofRun();
}

void tests::longString() {
	// Fb string has 3 tiered storage
	fbstart = std::chrono::high_resolution_clock::now();
	folly::fbstring fbstring = "SYmTshJf6kPjTrBj6Td9hkO3AEbx4ph9btYoMQupEkRozm5pQA2tclPVVb00opJb9MrYLbj8o2IOvYjTfCrtcpwCTtsFJlufuW0dOelyWgbFlLdYUoTJSD7nXBYh8IS79ZPEkmKnCVvU9Zx2ntiOFM72iL3kVLjiYwh32rw6JHYw4fX7wyu8xF67SN4e5W5U7UrqFNLkPl2B6QowJfoUHIxhbYpfmGrCFk456W7pIz5QIf6uL2roijjBn0JN6cFUlekj7L3GBa1ixZJHwb4OjAhyqCl8MkRQWGrKXs9tPMJLnDcAwJjv8QWGrry8KJGHBREg9xL0Nftnug5EFfxncd75hFWVfa9eX20tortAk5T4CAO3H295Crl4LDyfthkYjjOxCISagqCSuHnXjfwV4gOZAhoyKxcARv6Jo8qEFU1ASRdqrNfl0ue3qPigusIIuknsUAb4xkxZm2QlZ5SCkWLA2i0HG9wVH1BO67seqvGcDPnRqvQI";
	fbend = std::chrono::high_resolution_clock::now();

	libcstart = std::chrono::high_resolution_clock::now();
	std::string std_string = "SYmTshJf6kPjTrBj6Td9hkO3AEbx4ph9btYoMQupEkRozm5pQA2tclPVVb00opJb9MrYLbj8o2IOvYjTfCrtcpwCTtsFJlufuW0dOelyWgbFlLdYUoTJSD7nXBYh8IS79ZPEkmKnCVvU9Zx2ntiOFM72iL3kVLjiYwh32rw6JHYw4fX7wyu8xF67SN4e5W5U7UrqFNLkPl2B6QowJfoUHIxhbYpfmGrCFk456W7pIz5QIf6uL2roijjBn0JN6cFUlekj7L3GBa1ixZJHwb4OjAhyqCl8MkRQWGrKXs9tPMJLnDcAwJjv8QWGrry8KJGHBREg9xL0Nftnug5EFfxncd75hFWVfa9eX20tortAk5T4CAO3H295Crl4LDyfthkYjjOxCISagqCSuHnXjfwV4gOZAhoyKxcARv6Jo8qEFU1ASRdqrNfl0ue3qPigusIIuknsUAb4xkxZm2QlZ5SCkWLA2i0HG9wVH1BO67seqvGcDPnRqvQI";
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