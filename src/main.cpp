#include "tests.hpp"

int main() {
	printf("Libstd++ version is %d.%d\n", __GLIBC__, __GLIBC_MINOR__);
	tests t;
	return 0;
}