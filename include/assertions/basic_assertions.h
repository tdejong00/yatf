#ifndef __YATF_BASIC_ASSERTIONS_H__
#define __YATF_BASIC_ASSERTIONS_H__

#include <string>
#include <stdexcept>

#include "type_traits.h"

/**
 * @brief Provides basic assertions for verifying specific conditions within test cases.
 */
namespace assert {
    /**
     * @brief Error thrown when an assertion has failed.
     */
    class assertion_failed : public std::runtime_error {
        public:
            /**
             * @brief Construct a new instance of the assertion failed error.
             */
            explicit assertion_failed() : std::runtime_error("") { }

            /**
             * @brief Construct a new instance of the assertion failed error using the specified message.
             *
             * @param message The details of the assertion.
             */
            explicit assertion_failed(const std::string &message) : std::runtime_error("assertion failed: " + message) { }
    };

    /**
     * @brief Error thrown when an assertion has passed.
     */
    class assertion_passed : public std::runtime_error {
        public:
            /**
             * @brief Construct a new instance of the assertion passed error.
             */
            explicit assertion_passed() : std::runtime_error("") { }

            /**
             * @brief Construct a new instance of the assertion passed error using the specified message.
             *
             * @param message The details of the assertion.
             */
            explicit assertion_passed(const std::string &message) : std::runtime_error("assertion passed: " + message) { }
    };

    /**
     * @brief Immediately fails the assertion.
     *
     * @param message An optional message for the details of the failure.
     */
    void fail(const std::string &message = "");

    /**
     * @brief Immediately passes the assertion.
     *
     * @param message An optional message for the details of the success.
     */
    void pass(const std::string &message = "");

    /**
     * @brief Displays a message.
     * 
     * @param message The message to display.
     */
    void message(const std::string &message);

    /**
     * @brief Asserts that the condition is true.
     *
     * @param condition The condition to check.
     */
    void is_true(const bool &condition);

    /**
     * @brief Asserts that the condition is false.
     *
     * @param condition The condition to check.
     */
    void is_false(const bool &condition);

    /**
     * @brief Asserts that a value is equal to another value.
     *
     * @tparam T The type of the first value.
     * @tparam U The type of the second value.
     * @param value1 The first value.
     * @param value2 The second value.
     */
    template<typename T, typename U>
    typename std::enable_if<type_traits::are_equality_comparable<T, U>::value>::type is_equal(const T &value1, const U &value2) {
        if (!(value1 == value2)) {
            throw assertion_failed("expected values to be equal, but they were not");
        }
    }

    /**
     * @brief Asserts that a value is not equal to another value.
     *
     * @tparam T The type of the first value.
     * @tparam U The type of the second value.
     * @param value1 The first value.
     * @param value2 The second value.
     */
    template<typename T, typename U>
    typename std::enable_if<type_traits::are_equality_comparable<T, U>::value>::type is_not_equal(const T &value1, const U &value2) {
        if (value1 == value2) {
            throw assertion_failed("expected values to not be equal, but they were");
        }
    }

    /**
     * @brief Asserts that a value is the same instance as another value.
     *
     * @tparam T The type of the values.
     * @param value1 The first value.
     * @param value2 The second value.
     */
    template<typename T>
    void is_same(const T &value1, const T &value2) {
        if (&value1 != &value2) {
            throw assertion_failed("expected values to be the same instance, but they were not");
        }
    }

    /**
     * @brief Asserts that a value is not the same instance as another value.
     *
     * @tparam T The type of the values.
     * @param value1 The first value.
     * @param value2 The second value.
     */
    template<typename T>
    void is_not_same(const T &value1, const T &value2) {
        if (&value1 == &value2) {
            throw assertion_failed("expected values to be different instances, but they were not");
        }
    }
}

#endif