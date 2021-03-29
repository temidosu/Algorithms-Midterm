

# About
This repo contains tests benchmarking libc's ```string``` against folly's ```string``` implementation.

## Building
```git clone https://github.com/facebook/folly.git```
Install folly dependencies (listed in folly repo)
Run ```build.sh```. This will build folly and install it in ```tmp``` by default. This will take a while.
Navigate to the temp folder that folly is located in. For me, this was ```/tmp/fbcode_builder_getdeps-ZhomeZtemiZAlgorithmsZfollyZbuildZfbcode_builder/installed/folly/lib/cmake```


clone this repo

```mkdir build && cd build```
```cmake.. -DCMAKE_PREFIX_PATH=path/to/folly```

CMake will link this project against the static folly library built by ```build.sh``` If you encounter any errors, please make sure that all folly dependencies are installed and that you have specified the correct folder to link against.
