#ifndef __ASSERT_H__
#define __ASSERT_H__

#include <iostream>

/**
 * @brief Provides assertion function for verifying specific conditions within test cases.
 */
namespace assert {
    /**
     * Asserts that the two values are equal.
     * @tparam T Type of the values.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T>
    void is_equal(T actual, T expected) {
        if (actual != expected) {
            printf("Assertion failed: %s != %s\n", std::to_string(actual).c_str(), std::to_string(expected).c_str());
        }
        else {
            printf("Assertion succeeded: %s == %s\n", std::to_string(actual).c_str(), std::to_string(expected).c_str());
        }
    }
}

#endif