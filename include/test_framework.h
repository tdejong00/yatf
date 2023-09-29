#ifndef __TEST_FRAMEWORK_H__
#define __TEST_FRAMEWORK_H__

#include "test_runner.h"
#include "test_assert.h"

#define TEST_CASE(name) \
    class __TEST__CASE__##name##__ { \
        public: \
            __TEST__CASE__##name##__() { \
                test_framework::test_case t = {#name, __FILE__, __LINE__, &__##name##__}; \
                test_framework::test_runner::register_test_case(__FILE__, t); \
            } \
            static void __##name##__(); \
    } __TEST__CASE__##name##__; \
    void __TEST__CASE__##name##__::__##name##__()

#define IS_EQUAL(actual, expected) \
    assert::is_equal(actual, expected, __FILE__, __LINE__);

#endif
