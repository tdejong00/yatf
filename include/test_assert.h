#ifndef __TEST_ASSERT_H__
#define __TEST_ASSERT_H__

#include <string>
#include <sstream>

/**
 * @brief Error thrown when an assertion has failed.
 */
class assertion_error : public std::runtime_error {
    public:
        explicit assertion_error(std::string message) : std::runtime_error("assertion failed: " + message) { }
};

/**
 * @brief Provides assertion function for verifying specific conditions within test cases.
 */
namespace assert {
    /**
     * @brief Attempts to convert a value to its string representation.
     * 
     * @tparam t The type of the value.
     * @param value The value to convert.
     * @return The string representation of the value.
     */
    template<typename t>
    std::string to_string(const t &value) {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }

    /**
     * Asserts that the two values are equal. Throws an assertion_error on failure.
     * @tparam t Type of the values.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename t>
    void is_equal(t actual, t expected) {
        if (actual != expected) {
            throw assertion_error("expected " + assert::to_string(expected) + ", but was " + assert::to_string(actual));
        }
    }
}

#endif