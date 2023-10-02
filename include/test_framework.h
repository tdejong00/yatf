#ifndef __TEST_FRAMEWORK_H__
#define __TEST_FRAMEWORK_H__

#include "test_registry.h"
#include "test_assert.h"

/**
 * @brief TODO
 */
#define TEST_CASE(name) \
    class __TEST__CASE__##name##__ { \
        public: \
            __TEST__CASE__##name##__() { \
                test_framework::test_case test_case = {#name, __FILE__, __LINE__, &__##name##__}; \
                test_framework::test_registry::register_test_case(__FILE__, test_case); \
            } \
            static void __##name##__(); \
    } __TEST__CASE__##name##__; \
    void __TEST__CASE__##name##__::__##name##__()

#endif
