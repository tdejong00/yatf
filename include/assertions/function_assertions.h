#ifndef __YATF_FUNCTION_ASSERTIONS_H__
#define __YATF_FUNCTION_ASSERTIONS_H__

#include <functional>

#include "basic_assertions.h"

namespace assert {
    /**
     * Provides function assertions for verifying specific conditions within test cases.
     */
    namespace function {
        /**
         * Asserts that a function or lambda expression throws an exception.
         *
         * @param function The function or lambda expression to be executed.
         */
        void throws(const std::function<void()> &function);

        /**
         * Asserts that a function or lambda expression throws a specific exception.
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
         * Asserts that a function or lambda expression does not throw any exception.
         *
         * @param function The function or lambda expression to be executed.
         */
        void does_not_throw(const std::function<void()> &function);
    }
}

#endif