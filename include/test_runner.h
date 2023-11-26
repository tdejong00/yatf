#ifndef __YATF_TEST_RUNNER_H__
#define __YATF_TEST_RUNNER_H__

#include <string>

#include "test.h"
#include "test_reporter.h"

namespace yatf {
    /**
     * Runs the test cases of test suites and reports the results using a test reporter.
     */
    class test_runner {
        public:
            /**
             * Constructs a new instance of the test runner using the default report options.
             */
            test_runner();

            /**
             * Constructs a new instance of the test runner using the given report options.
             * 
             * @param options Options for controlling the announcements and reports.
             */
            test_runner(const report_options &options);

            /**
             * Runs a specific test suite.
             * 
             * @param test_suite The name of the test suite to run.
             * 
             * @return Whether the test suite was found.
             */
            bool run_test_suite(const std::string &suite_name);

            /**
             * Runs all registered test cases.
             */
            void run_all_tests();

            /**
             * Lists all registered test cases.
             */
            void list_all_tests() const;

        private:
            /**
             * Runs a specific test suite.
             * 
             * @param test_suite The test suite to run.
             */
            void run_test_suite(const test_suite &test_suite);

            /**
             * Runs a specific test case.
             * 
             * @param test_case The test case to run.
             */
            void run_test_case(const test_case &test_case);

            test_reporter reporter;
            test_statistics statistics;
    };
}

#endif
