# Folly vs Libstd++

## About libstd++
Libstd++ is the default C/C++ library that ships with gcc/g++. A mirror of its source code can be found here - https://github.com/gcc-mirror/gcc/tree/master/libstdc%2B%2B-v3

## Why Folly?
Folly is "a library of C++14 components designed with practicality and efficiency in mind"(1). It aims to provide performant library code that complements the standard library. String performance is a critical part of overall performance, and according to a Cppcon talk given by Nicholas Ormrod (4), 18% of CPU time facebook programs spend in the stl is spent in ```<string>```. With such widespread usage, even minor optimizations can translate to significant performance gains for programs.

## Folly vs Libstd++ String
Both string classes implement ```std::string``` according to the standard. ```folly::fbstring``` has a few different features in its implementation compared to ```std::string```, which should theoretically give it a performance gain, if only a small one. To allocate memory, ```std::string``` uses an ```std::allocator``` to allocate heap memory on its behalf. In contrast,  ```folly::fbstring``` uses a clever three tiered storage approach (2). For a string with 23 chars or fewer, fbstring stores the string on the stack. For a string with 24 - 255 chars, folly stores on the heap, and "copies eagerly". For strings with greater than 255 chars, folly will use lazy copying (folly will use copy on write to defer memory allocation). Folly promises drop in compatability with ```std::string``` 

### Find()
Folly promises significantly better performance for ```find()``` (documentation suggests 30x speed improvements)

## Folly specific
Folly readily converts between ```std::string``` and ```folly::fbstring```.

## Testing methodology
All tests were run on an i5 9300H running at 2.4 GHz. Tests were compiled in release mode using Clang 12. libstd++ version was 2.27.


## Results
The results were almost a wash. On a single string allocation, std::string beat folly::fbstring. However, with a std::vector with 100k elements ```reserve()```'d, folly beat libc string at small string (less than 23 chars).  

## Conclusion
In conclusion, fbstring beats libc string with a large number of allocations. However, that doesn't mean that c++ programmers should universally dump libc in exchange for folly or other stl alternatives. The performance gains were extremely minor and measurable improvements would likely only be seen in extremely large projects like in facebook. In those same large projects, the cost of adding another dependency, switching to folly, and testing to make sure the switch to ```folly::string``` didn't break anything would likely outweigh the miniscule gains in string performance. 
## Further Reading

std::string documentation - https://en.cppreference.com/w/cpp/string/basic_string

libc c-string documentation - https://www.gnu.org/software/libc/manual/html_mono/libc.html#Representation-of-Strings


## References

1) https://github.com/facebook/folly
2) https://github.com/facebook/folly/blob/master/folly/docs/FBString.md
3) Testing repo - https://github.com/temidosu/Algorithms-Midterm
4) https://www.youtube.com/watch?v=kPR8h4-qZdk