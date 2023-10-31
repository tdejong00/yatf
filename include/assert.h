#ifndef __YATF_ASSERT_H__
#define __YATF_ASSERT_H__

#include <string>
#include <sstream>

/**
 * @brief Provides assertion function for verifying specific conditions within test cases.
 */
namespace assert {
    /**
     * @brief Error thrown when an assertion has failed.
     */
    class assertion_error : public std::runtime_error {
        public:
            explicit assertion_error(const std::string &message) : std::runtime_error("assertion failed: " + message) { }
    };

    /**
     * @brief Assertion object for performing various assertions on a value.
     *
     * @tparam T The type of the value being asserted.
     */
    template<typename T>
    class assertion {
        public:
            /**
             * @brief Constructs a new instance of the assertion object using the specified value.
             *
             * @param value The value to be asserted.
             */
            explicit assertion(const T &value) : value(value) {}

            /**
             * @brief Asserts that the value is equal to the expected value.
             *
             * @tparam U The type of the expected value.
             * @param expected The expected value.
             */
            template <typename U>
            void is_equal_to(const U &expected) {
                if (!(value == expected)) {
                    std::stringstream ss;
                    ss << "expected " << expected << ", but was " << value;
                    throw assertion_error(ss.str());
                }
            }

        private:
            T value;
    };

    /**
     * @brief Creates an assertion object for the specified value.
     *
     * @tparam T The type of the value.
     * @param value The value to be asserted.
     *
     * @return An assertion object for the value.
     */
    template<typename T>
    assertion<T> that(const T &value) {
        return assertion<T>(value);
    }
}

#endif