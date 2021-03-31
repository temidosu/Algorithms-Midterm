
# Folly
Folly is "a library of C++14 components designed with practicality and efficiency in mind" (1) It aims to provide performant library code that complements the standard library.

## Folly vs Libstd++ String
Both string classes implement ```std::string``` according to the standard. ```folly::fbstring``` has a few different features in its implementation compared to ```std::string```, which should theoretically give it a performance gain, if only a small one. To allocate memory, ```std::string``` uses an ```std::allocator```. In contrast,  ```folly::fbstring``` uses a clever three tiered storage approach(2). For a string with 23 or less chars, fbstring stores on the stack. For a string with 24 - 255 chars, folly stores on the heap, and "copies eagerly". For strings with greater than 255 chars, folly will use lazy copying (fbstring will use reference counting). Folly promises drop in compatability with ```std::string``` 

### Find()
Folly promises significantly better performance for find (documentation suggests 30x speed improvements)

## Folly specific
Folly readily converts between ```std::string``` and ```folly::fbstring```.

## Testing methodology
All tests were run on an i5 9300H running at 2.4 GHz. Tests were compiled in release mode using Clang 12. LibC version was 2.27.



## Further Reading

std::string documentation - https://en.cppreference.com/w/cpp/string/basic_string

libc c-string documentation - https://www.gnu.org/software/libc/manual/html_mono/libc.html#Representation-of-Strings


## References

1) https://github.com/facebook/folly
2) https://github.com/facebook/folly/blob/master/folly/docs/FBString.md
