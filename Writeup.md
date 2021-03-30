
# Folly vs Libc++
Folly is "a library of C++14 components designed with practicality and efficiency in mind." It aims to provide performant library code that complements the standard library.

## Folly vs Libc++ string
Both string classes implement std::string according to the standard. ```folly::fbstring``` has a few different features in its implementation compared to ```std::string```, which should theoretically give it a performance gain, if only a small one. To allocate memory, ```std::string``` uses an ```std::allocator```. In contrast,  ```folly::fbstring``` uses a clever three tiered storage approach. For a string with 23 or less chars, fbstring stores on the stack. For a string with 24 - 255 chars, folly stores on the heap, and "copies eagerly". For strings with greater than 255 chars, folly will "copy lazily" (fbstring will count the references to this string). Folly promises drop in compatability with ```std::string``` 

### Find()
Folly promises significantly better performance for find (documentation suggests 30x speed improvements)

## Folly specific