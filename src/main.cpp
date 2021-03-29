#include <folly/FBString.h>
#include <iostream>
#include <string> 

int main(){
	printf("Libc version is %d.%d\n", __GLIBC__, __GLIBC_MINOR__);
    folly::fbstring str = "hello, world!";
    std::cout << str << std::endl;
    return 0;
}