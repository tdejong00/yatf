#include <climits>
#include <stdexcept>

#include "lib.h"

int add(int a, int b) {
    if (a >= 0 && b > (INT_MAX - a)) {
        throw std::underflow_error("Adding " + std::to_string(a) + " and " + std::to_string(b) + " would result in an overflow");
    }
    else if (a < 0 && b < (INT_MIN - a)) {
        throw std::underflow_error("Adding " + std::to_string(a) + " and " + std::to_string(b) + " would result in an underflow");
    }
    return a + b;
}
