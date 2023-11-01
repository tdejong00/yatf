#ifndef __YATF_ASSERT_H__
#define __YATF_ASSERT_H__

#include <string>
#include <sstream>
#include <functional>
#include <type_traits>

/**
 * @brief Provides assertion function for verifying specific conditions within test cases.
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
     * @brief Asserts that the value is equal to the expected value.
     *
     * @tparam T The type of the actual value.
     * @tparam U The type of the expected value.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T, typename U>
    typename std::enable_if<std::is_same<T, U>::value>::type are_equal(const T &actual, const U &expected) {
        if (!(actual == expected)) {
            throw assertion_failed("expected values to be equal, but they were not");
        }
    }

    /**
     * @brief Asserts that the value is not equal to the expected value.
     *
     * @tparam T The type of the actual value.
     * @tparam U The type of the expected value.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T, typename U>
    typename std::enable_if<std::is_same<T, U>::value>::type are_not_equal(const T &actual, const U &expected) {
        if (actual == expected) {
            throw assertion_failed("expected values to not be equal, but they were");
        }
    }

    /**
     * @brief Asserts that two values are the same instance.
     *
     * @tparam T The type of the values.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T>
    void are_same(const T &actual, const T &expected) {
        if (&actual != &expected) {
            throw assertion_failed("expected values to be the same instance, but they were not");
        }
    }

    /**
     * @brief Asserts that two pointers are pointing to the same instance.
     *
     * @tparam T The type of the values.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T>
    void are_same(const T *actual, const T *expected) {
        if (actual != expected) {
            throw assertion_failed("expected pointers to be pointing to the same instance, but they are not");
        }
    }

    /**
     * @brief Asserts that two values are different instances.
     *
     * @tparam T The type of the values.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T>
    void are_not_same(const T &actual, const T &expected) {
        if (&actual == &expected) {
            throw assertion_failed("expected values to be different instances, but they were not");
        }
    }

    /**
     * @brief Asserts that two pointers are pointing to different instances.
     *
     * @tparam T The type of the values.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T>
    void are_not_same(const T *actual, const T *expected) {
        if (actual == expected) {
            throw assertion_failed("expected pointers to be pointing to different instances, but they were not");
        }
    }

    /**
     * @brief Asserts that the value is equal to zero.
     * 
     * @tparam T The type of the value, has to be either an integral type or a floating point type.
     * @param value The value to check.
     */
    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value>::type is_zero(const T &value) {
        if (value != 0) {
            throw assertion_failed("expected value to be zero, but it was not");
        }
    }

    /**
     * @brief Asserts that the value is not equal to zero.
     * 
     * @tparam T The type of the value, has to be either an integral type or a floating point type.
     * @param value The value to check.
     */
    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value>::type is_not_zero(const T &value) {
        if (value == 0) {
            throw assertion_failed("expected value to not be zero, but it was");
        }
    }

    /**
     * @brief Asserts that a pointer is null.
     *
     * @tparam T The type of the pointer.
     * @param pointer The pointer to check.
     */
    template<typename T>
    void is_null(const T *pointer) {
        if (pointer != nullptr) {
            throw assertion_failed("expected pointer to be null, but it was not");
        }
    }

    /**
     * @brief Asserts that a pointer is not null.
     *
     * @tparam T The type of the pointer.
     * @param pointer The pointer to check.
     */
    template<typename T>
    void is_not_null(const T *pointer) {
        if (pointer == nullptr) {
            throw assertion_failed("expected pointer to not be null, but it was");
        }
    }

    /**
     * @brief Asserts that a function or lambda expression throws an exception.
     *
     * @param function The function or lambda expression to be executed.
     */
    void throws(const std::function<void()> &function);

    /**
     * @brief Asserts that a function or lambda expression throws a specific exception.
     *
     * @tparam T The type of the exception expected to be thrown.
     * @param function The function or lambda expression to be executed.
     */
    template<typename T>
    void throws(const std::function<void()> &function) {
        try {
            function();
        }
        catch (const T &e) {
            throw assertion_passed();
        }
        catch (...) {
            throw assertion_failed("expected a specific exception to be thrown, but a different exception was thrown");
        }
        throw assertion_failed("expected a specific exception to be thrown, but it was not");
    }

    /**
     * @brief Asserts that a function or lambda expression does not throw any exception.
     *
     * @param function The function or lambda expression to be executed.
     */
    void does_not_throw(const std::function<void()> &function);
}

#endif