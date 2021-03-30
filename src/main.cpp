#include "tests.hpp"

int main() {
	printf("Libc version is %d.%d\n", __GLIBC__, __GLIBC_MINOR__);
	tests t("results.txt");
	return 0;
}