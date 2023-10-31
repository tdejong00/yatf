#ifndef __YATF_TEST_RUNNER_H__
#define __YATF_TEST_RUNNER_H__

#include <vector>

#include "test_reporter.h"
#include "assert.h"

namespace yatf {
    /**
     * @brief Runs the test cases of test suites and reports the results using a test reporter.
     */
    class test_runner {
        public:
            /**
             * @brief Constructs a new instance of the test runner using the default report options.
             */
            test_runner();

            /**
             * @brief Constructs a new instance of the test runner using the given report options.
             * 
             * @param options Options for controlling the announcements and reports.
             */
            test_runner(report_options options);

            /**
             * @brief Runs a specific test suite.
             * 
             * @param test_suite The name of the test suite to run.
             * 
             * @return Whether the test suite was found.
             */
            bool run_test_suite(const char *suite_name);

            /**
             * @brief Runs all registered test cases.
             */
            void run_all_tests();

            /**
             * @brief Lists all registered test cases.
             */
            static void list_all_tests();

        private:
            /**
             * @brief Runs a specific test suite.
             * 
             * @param test_suite The test suite to run.
             */
            void run_test_suite(test_suite test_suite);

            /**
             * @brief Runs a specific test case.
             * 
             * @param test_case The test case to run.
             */
            void run_test_case(test_case test_case);

            test_reporter reporter;
            test_statistics statistics;
    };
}

#endif
