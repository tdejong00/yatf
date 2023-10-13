#ifndef __YATF_H__
#define __YATF_H__

/**
 * @brief The root namespace for YATF.
 *
 * This namespace contains all the components and utilities necessary for creating,
 * registering, and running tests, as well as reporting their results. The framework
 * includes an assertion library, a static test registry for compile-time test
 * registration, a test runner for executing registered tests at runtime, and a
 * test reporter for displaying test outcomes. Additionally, it provides macros for
 * easily registering tests and performing assertions within test cases.
 */
namespace yatf {
    /**
     * @brief Prints the help display.
     */
    void print_help();
    
    /**
     * @brief Initializes the framework with the given command
     * line arguments and runs the tests using those options.
     * 
     * @param argc The amount of command line arguments.
     * @param argv The command line arguments.
     * @return The exit code.
     */
    int init(int argc, char **argv);
}

#include "test_registry.h"
#include "test_reporter.h"
#include "test_runner.h"
#include "assert.h"

#define TEST_CASE(name) \
    class __TEST__CASE__##name##__ { \
        public: \
            __TEST__CASE__##name##__() { \
                yatf::test_case test_case = {#name, __FILE__, __LINE__, &__##name##__}; \
                yatf::test_registry::register_test_case(__FILE__, test_case); \
            } \
            static void __##name##__(); \
    } __TEST__CASE__##name##__; \
    void __TEST__CASE__##name##__::__##name##__()

#endif
