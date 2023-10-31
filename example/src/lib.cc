#include <climits>
#include <stdexcept>

#include "lib.h"

int add(int first, int second) {
    if (first >= 0 && second > (INT_MAX - first)) {
        throw std::underflow_error("Adding " + std::to_string(first) + " and " + std::to_string(second) + " would result in an overflow");
    }
    if (first < 0 && second < (INT_MIN - first)) {
        throw std::underflow_error("Adding " + std::to_string(first) + " and " + std::to_string(second) + " would result in an underflow");
    }
    return first + second;
}
