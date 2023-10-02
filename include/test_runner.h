#ifndef __TEST_RUNNER_H__
#define __TEST_RUNNER_H__

#include <vector>

#include "test_reporter.h"

namespace test_framework {
    /**
     * @brief Runs the test cases of test suites and reports the results.
     */
    class test_runner {
        public:
            /**
             * @brief Constructs a new instance of the test runner.
             * 
             * @param reporter The test reporter to use for reporting on test cases.
             */
            test_runner(test_reporter reporter);

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
            void list_all_tests();

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
