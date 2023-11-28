# YATF: Yet Another Testing Framework

YATF is a lightweight testing framework designed for simplicity and ease of use. It provides a robust set of features for writing and executing tests in C++ projects. This is a hobby project and was made for educational purposes.

## Installation

To integrate YATF into your project, follow these steps:

```sh
git clone https://github.com/tdejong00/yatf.git
cd yatf
make
sudo make install
```

## Usage

See the examples directory for an example of how to use the library. In short:

1. Write a test file:
```c++
#include <yatf/yatf.h>

TEST_CASE(my_test) {
    assert::is_equal(1 + 2, 3);
}
```
2. Compile test file:
```sh
g++ test.cc -lyatf -o test
```
3. Run test file:
```sh
./test
```

## Future Work

- Multiple test suites per file
- Test fixtures
- Improving the finding and execution of tests
- Mocking

## License

This project is licensed under the MIT License. See the LICENSE.md file for details.