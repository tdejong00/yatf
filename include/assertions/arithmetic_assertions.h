#ifndef __YATF_ARITHMETIC_ASSERTIONS_H__
#define __YATF_ARITHMETIC_ASSERTIONS_H__

#include "basic_assertions.h"

namespace assert {
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
     * @brief Asserts that the value is positive.
     * 
     * @tparam T The type of the value, has to be either an integral type or a floating point type.
     * @param value The value to check.
     */
    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value>::type is_positive(const T &value) {
        if (value < 0) {
            throw assertion_failed("expected value to be positivie, but it was not");
        }
    }

    /**
     * @brief Asserts that the value is negative.
     * 
     * @tparam T The type of the value, has to be either an integral type or a floating point type.
     * @param value The value to check.
     */
    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value>::type is_negative(const T &value) {
        if (value >= 0) {
            throw assertion_failed("expected value to be negative, but it was not");
        }
    }

    /**
     * @brief Asserts that the value is greater than the expected value.
     * 
     * @tparam T The type of the value, has to be either an integral type or a floating point type.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value>::type is_greater_than(const T &actual, const T &expected) {
        if (actual <= expected) {
            throw assertion_failed("expected value to be greater, but it was not");
        }
    }

    /**
     * @brief Asserts that the value is greater or equal than the expected value.
     * 
     * @tparam T The type of the value, has to be either an integral type or a floating point type.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value>::type is_greater_or_equal_than(const T &actual, const T &expected) {
        if (actual < expected) {
            throw assertion_failed("expected value to be greater or equal, but it was not");
        }
    }

    /**
     * @brief Asserts that the value is less than the expected value.
     * 
     * @tparam T The type of the value, has to be either an integral type or a floating point type.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value>::type is_less_than(const T &actual, const T &expected) {
        if (actual >= expected) {
            throw assertion_failed("expected value to be less, but it was not");
        }
    }

    /**
     * @brief Asserts that the value is less or equal than the expected value.
     * 
     * @tparam T The type of the value, has to be either an integral type or a floating point type.
     * @param actual The actual value.
     * @param expected The expected value.
     */
    template<typename T>
    typename std::enable_if<std::is_arithmetic<T>::value>::type is_less_or_equal_than(const T &actual, const T &expected) {
        if (actual > expected) {
            throw assertion_failed("expected value to be less or equal, but it was not");
        }
    }
}

#endif