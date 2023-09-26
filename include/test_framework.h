#ifndef __TEST_FRAMEWORK_H__
#define __TEST_FRAMEWORK_H__

#include "test_runner.h"
#include "assertions.h"

/**
 * Defines and registers a test case to be run by the test runner.
 */
#define TEST_CASE(test_case) \
    class __TEST__CASE__##test_case##__ { \
        public: \
            __TEST__CASE__##test_case##__() { \
                test_framework::test_runner::register_test({#test_case, &__##test_case##__}); \
            } \
            static void __##test_case##__(); \
    } __TEST__CASE__##test_case##__; \
    void __TEST__CASE__##test_case##__::__##test_case##__()

#endif