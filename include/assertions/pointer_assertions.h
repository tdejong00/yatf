#ifndef __YATF_POINTER_ASSERTIONS_H__
#define __YATF_POINTER_ASSERTIONS_H__

#include "basic_assertions.h"

namespace assert {
    /**
     * Provides pointer assertions for verifying specific conditions within test cases.
     */
    namespace pointer {
        /**
         * Asserts that a pointer is null.
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
         * Asserts that a pointer is not null.
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
         * Asserts that a pointer is pointing to the same value as another pointer.
         *
         * @tparam T The type of the values.
         * @param actual The actual value.
         * @param expected The expected value.
         */
        template<typename T>
        void is_same(const T *actual, const T *expected) {
            if (actual != expected) {
                throw assertion_failed("expected pointers to be pointing to the same instance, but they are not");
            }
        }

        /**
         * Asserts that a pointer is not pointing to the same value as another pointer.
         *
         * @tparam T The type of the values.
         * @param actual The actual value.
         * @param expected The expected value.
         */
        template<typename T>
        void is_not_same(const T *actual, const T *expected) {
            if (actual == expected) {
                throw assertion_failed("expected pointers to be pointing to different instances, but they were not");
            }
        }
    }
}

#endif