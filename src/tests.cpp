#include "tests.hpp"
#include <math.h>

tests::tests() {
	defaultConstruction();

	smallString();
	mediumString();
	longString();

	shortFind();
	mediumFind();
	longFind();
	// TODO: Generate pretty graphs for tests
}

void tests::defaultConstruction() {
	std::cout << "Default Construction - ";
	// Arrays are default constructed
	fbstart = std::chrono::high_resolution_clock::now();
	folly::fbstring fbarr[100000];
	fbend = std::chrono::high_resolution_clock::now();

	libstdstart = std::chrono::high_resolution_clock::now();
	std::string stdarr[100000];
	libstdend = std::chrono::high_resolution_clock::now();

	outputResultsofRun();
}

void tests::smallString() {
	std::cout << "Small String - ";
	// Fb string has 3 tiered storage
	std::vector<folly::fbstring> fbvec;
	fbvec.reserve(100000);

	fbstart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; ++i) {
		fbvec.push_back("abdefg");
	}
	fbend = std::chrono::high_resolution_clock::now();

	std::vector<std::string> stdvec;
	stdvec.reserve(100000);

	libstdstart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; ++i) {
		stdvec.push_back("abdefg");
	}
	libstdend = std::chrono::high_resolution_clock::now();

	outputResultsofRun();
}

void tests::mediumString() {
	std::cout << "Medium String - ";
	std::vector<folly::fbstring> fbvec;
	fbvec.reserve(100000);

	fbstart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; ++i) {
		fbvec.push_back("C6A4bHsmu8BWJrBqBbNPMhy7AVEw88EVGJICwZQ0WtHfpvsPcBkRYCPRAd8k8HoYu1yWKINaR152lW93KVW7ORAZLjocDuvFz3WFFpJzoosx6JHfCvLotpTMPEc5884yhE7C1HhqdmD29TgrOOvkw5Np51SBS0Sg4nOud74Ga6e9Uu9RaU0X2VRl8aC4jWUOM2YNoIvjeav8Pkfvhk0glP80jXDYaJwLmcpV8fuTza2dkrhzuvX1u5UeG4");
	}
	fbend = std::chrono::high_resolution_clock::now();

	std::vector<std::string> stdvec;
	stdvec.reserve(100000);

	libstdstart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; ++i) {
		stdvec.push_back("C6A4bHsmu8BWJrBqBbNPMhy7AVEw88EVGJICwZQ0WtHfpvsPcBkRYCPRAd8k8HoYu1yWKINaR152lW93KVW7ORAZLjocDuvFz3WFFpJzoosx6JHfCvLotpTMPEc5884yhE7C1HhqdmD29TgrOOvkw5Np51SBS0Sg4nOud74Ga6e9Uu9RaU0X2VRl8aC4jWUOM2YNoIvjeav8Pkfvhk0glP80jXDYaJwLmcpV8fuTza2dkrhzuvX1u5UeG4");
	}
	libstdend = std::chrono::high_resolution_clock::now();

	outputResultsofRun();
}

void tests::longString() {
	std::cout << "Long String - ";
	std::vector<folly::fbstring> fbvec;
	fbvec.reserve(100000);

	fbstart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; ++i) {
		fbvec.push_back("SYmTshJf6kPjTrBj6Td9hkO3AEbx4ph9btYoMQupEkRozm5pQA2tclPVVb00opJb9MrYLbj8o2IOvYjTfCrtcpwCTtsFJlufuW0dOelyWgbFlLdYUoTJSD7nXBYh8IS79ZPEkmKnCVvU9Zx2ntiOFM72iL3kVLjiYwh32rw6JHYw4fX7wyu8xF67SN4e5W5U7UrqFNLkPl2B6QowJfoUHIxhbYpfmGrCFk456W7pIz5QIf6uL2roijjBn0JN6cFUlekj7L3GBa1ixZJHwb4OjAhyqCl8MkRQWGrKXs9tPMJLnDcAwJjv8QWGrry8KJGHBREg9xL0Nftnug5EFfxncd75hFWVfa9eX20tortAk5T4CAO3H295Crl4LDyfthkYjjOxCISagqCSuHnXjfwV4gOZAhoyKxcARv6Jo8qEFU1ASRdqrNfl0ue3qPigusIIuknsUAb4xkxZm2QlZ5SCkWLA2i0HG9wVH1BO67seqvGcDPnRqvQI");
	}
	fbend = std::chrono::high_resolution_clock::now();

	std::vector<std::string> stdvec;
	stdvec.reserve(100000);

	libstdstart = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < 100000; ++i) {
		stdvec.push_back("SYmTshJf6kPjTrBj6Td9hkO3AEbx4ph9btYoMQupEkRozm5pQA2tclPVVb00opJb9MrYLbj8o2IOvYjTfCrtcpwCTtsFJlufuW0dOelyWgbFlLdYUoTJSD7nXBYh8IS79ZPEkmKnCVvU9Zx2ntiOFM72iL3kVLjiYwh32rw6JHYw4fX7wyu8xF67SN4e5W5U7UrqFNLkPl2B6QowJfoUHIxhbYpfmGrCFk456W7pIz5QIf6uL2roijjBn0JN6cFUlekj7L3GBa1ixZJHwb4OjAhyqCl8MkRQWGrKXs9tPMJLnDcAwJjv8QWGrry8KJGHBREg9xL0Nftnug5EFfxncd75hFWVfa9eX20tortAk5T4CAO3H295Crl4LDyfthkYjjOxCISagqCSuHnXjfwV4gOZAhoyKxcARv6Jo8qEFU1ASRdqrNfl0ue3qPigusIIuknsUAb4xkxZm2QlZ5SCkWLA2i0HG9wVH1BO67seqvGcDPnRqvQI");
	}
	libstdend = std::chrono::high_resolution_clock::now();

	outputResultsofRun();
}

void tests::outputResultsofRun() {
	std::chrono::duration<double> follyDuration = fbend - fbstart;
	std::chrono::duration<double> libcDuration = libstdend - libstdstart;

	std::cout << std::fixed << std::setprecision(9) << std::showpoint;

	std::cout << "folly: " << follyDuration.count() << " sec. libstd++: "
			  << libcDuration.count() << " sec." << std::endl;
}

void tests::shortFind() {
	std::cout << "Small find() - ";
	folly::fbstring fbstring = "abcd";
	std::string stdstring = "abcd";

	fbstart = std::chrono::high_resolution_clock::now();
	fbstring.find('a');
	fbstring.find('b');
	fbstring.find('c');
	fbend = std::chrono::high_resolution_clock::now();

	libstdstart = std::chrono::high_resolution_clock::now();
	stdstring.find('a');
	stdstring.find('b');
	stdstring.find('c');
	libstdend = std::chrono::high_resolution_clock::now();

	outputResultsofRun();
}

void tests::mediumFind() {

	std::cout << "Medium find() - ";
	folly::fbstring fbstring = "C6A4bHsmu8BWJrBqBbNPMhy7AVEw88EVGJICwZQ0WtHfpvsPcBkRYCPRAd8k8HoYu1yWKINaR152lW93KVW7ORAZLjocDuvFz3WFFpJzoosx6JHfCvLotpTMPEc5884yhE7C1HhqdmD29TgrOOvkw5Np51SBS0Sg4nOud74Ga6e9Uu9RaU0X2VRl8aC4jWUOM2YNoIvjeav8Pkfvhk0glP80jXDYaJwLmcpV8fuTza2dkrhzuvX1u5UeG4";
	std::string stdstring = "C6A4bHsmu8BWJrBqBbNPMhy7AVEw88EVGJICwZQ0WtHfpvsPcBkRYCPRAd8k8HoYu1yWKINaR152lW93KVW7ORAZLjocDuvFz3WFFpJzoosx6JHfCvLotpTMPEc5884yhE7C1HhqdmD29TgrOOvkw5Np51SBS0Sg4nOud74Ga6e9Uu9RaU0X2VRl8aC4jWUOM2YNoIvjeav8Pkfvhk0glP80jXDYaJwLmcpV8fuTza2dkrhzuvX1u5UeG4";

	fbstart = std::chrono::high_resolution_clock::now();
	fbstring.find('B');
	fbstring.find('V');
	fbstring.find('6');
	fbend = std::chrono::high_resolution_clock::now();

	libstdstart = std::chrono::high_resolution_clock::now();
	stdstring.find('B');
	stdstring.find('V');
	stdstring.find('6');

	libstdend = std::chrono::high_resolution_clock::now();

	outputResultsofRun();
}

void tests::longFind() {
	std::cout << "Long find() - ";
	folly::fbstring fbstring = "SYmTshJf6kPjTrBj6Td9hkO3AEbx4ph9btYoMQupEkRozm5pQA2tclPVVb00opJb9MrYLbj8o2IOvYjTfCrtcpwCTtsFJlufuW0dOelyWgbFlLdYUoTJSD7nXBYh8IS79ZPEkmKnCVvU9Zx2ntiOFM72iL3kVLjiYwh32rw6JHYw4fX7wyu8xF67SN4e5W5U7UrqFNLkPl2B6QowJfoUHIxhbYpfmGrCFk456W7pIz5QIf6uL2roijjBn0JN6cFUlekj7L3GBa1ixZJHwb4OjAhyqCl8MkRQWGrKXs9tPMJLnDcAwJjv8QWGrry8KJGHBREg9xL0Nftnug5EFfxncd75hFWVfa9eX20tortAk5T4CAO3H295Crl4LDyfthkYjjOxCISagqCSuHnXjfwV4gOZAhoyKxcARv6Jo8qEFU1ASRdqrNfl0ue3qPigusIIuknsUAb4xkxZm2QlZ5SCkWLA2i0HG9wVH1BO67seqvGcDPnRqvQI";
	std::string stdstring = "SYmTshJf6kPjTrBj6Td9hkO3AEbx4ph9btYoMQupEkRozm5pQA2tclPVVb00opJb9MrYLbj8o2IOvYjTfCrtcpwCTtsFJlufuW0dOelyWgbFlLdYUoTJSD7nXBYh8IS79ZPEkmKnCVvU9Zx2ntiOFM72iL3kVLjiYwh32rw6JHYw4fX7wyu8xF67SN4e5W5U7UrqFNLkPl2B6QowJfoUHIxhbYpfmGrCFk456W7pIz5QIf6uL2roijjBn0JN6cFUlekj7L3GBa1ixZJHwb4OjAhyqCl8MkRQWGrKXs9tPMJLnDcAwJjv8QWGrry8KJGHBREg9xL0Nftnug5EFfxncd75hFWVfa9eX20tortAk5T4CAO3H295Crl4LDyfthkYjjOxCISagqCSuHnXjfwV4gOZAhoyKxcARv6Jo8qEFU1ASRdqrNfl0ue3qPigusIIuknsUAb4xkxZm2QlZ5SCkWLA2i0HG9wVH1BO67seqvGcDPnRqvQI";

	fbstart = std::chrono::high_resolution_clock::now();
	fbstring.find('U');
	fbstring.find('S');
	fbstring.find('T');
	fbend = std::chrono::high_resolution_clock::now();

	libstdstart = std::chrono::high_resolution_clock::now();
	stdstring.find('U');
	stdstring.find('S');
	stdstring.find('T');
	libstdend = std::chrono::high_resolution_clock::now();

	outputResultsofRun();
}