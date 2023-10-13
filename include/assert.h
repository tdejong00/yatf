#ifndef __YATF_ASSERT_H__
#define __YATF_ASSERT_H__

#include <string>
#include <sstream>

namespace yatf {
    /**
     * @brief Provides assertion function for verifying specific conditions within test cases.
     */
    namespace assert {
        /**
         * @brief Error thrown when an assertion has failed.
         */
        class assertion_error : public std::runtime_error {
            public:
                explicit assertion_error(std::string message) : std::runtime_error("assertion failed: " + message) { }
        };

        /**
         * @brief Attempts to convert a value to its string representation.
         * 
         * @tparam T The type of the value.
         * @param value The value to convert.
         * @return The string representation of the value.
         */
        template<typename T>
        std::string to_string(const T &value) {
            std::stringstream ss;
            ss << value;
            return ss.str();
        }

        /**
         * Asserts that the two values are equal. Throws an assertion_error on failure.
         * @tparam T Type of the values.
         * @param actual The actual value.
         * @param expected The expected value.
         */
        template<typename T>
        void is_equal(T actual, T expected) {
            if (actual != expected) {
                throw assertion_error("expected " + assert::to_string(expected) + ", but was " + assert::to_string(actual));
            }
        }
    }
}

#endif