#ifndef __TEST_REPORTER_H__
#define __TEST_REPORTER_H__

#include <cstdarg>
#include <vector>
#include <string>

#include "test_runner.h"

namespace test_framework {

    /**
     * @brief Represents the result of a test case.
     */
    enum test_result {
        unknown, /* The result has not been set. */
        failed, /* The test case has failed. */
        passed /* The test case has passed. */
    };

    /**
     * @brief Contains statistics about the executed test cases.
     * 
     */
    struct test_statistics {
        int n_total; /* Total number of test cases. */
        int n_passed; /* Number of test cases that have passed. */
        int n_failed; /* Number of test cases that have failed. */
    };

    /**
     * @brief Provides functionality for announcing tests and reporting test results.
     */
    class test_reporter {
        public:
            /**
             * @brief Lists the test suite.
             * 
             * @param test_suite The test suite to list.
             */
            static void list(test_suite test_suite);

            /**
             * @brief Lists the test case.
             * 
             * @param test_case The test case to list.
             */
            static void list(test_case test_case);

            /**
             * @brief Announces all test suites.
             * 
             * @param test_suites A list of test suites to announce.
             */
            static void announce(std::vector<test_suite> test_suites);

            /**
             * @brief Announces a single test suite.
             * 
             * @param test_suite The test suite to announce.
             */
            static void announce(test_suite test_suite);

            /**
             * @brief Reports the passing of a test case.
             * 
             * @param test_case The test case to report.
             */
            static void report(test_case test_case);

            /**
             * @brief Reports the failure of a test case.
             * 
             * @param test_case The test case to report.
             * @param failure_reason Reason for why the test case has failed.
             */
            static void report(test_case test_case, const char *failure_reason);

            /**
             * @brief Reports the result of all test cases.
             * 
             * @param test_statistics The statistics for the executed tests.
             */
            static void report(test_statistics test_statistics);

        private:
            /**
             * @brief Converts a test result to its string representation.
             * 
             * @param test_result The test result to convert.
             * @return The string representation of the test result.
             */
            static std::string to_string(test_result test_result);

            /**
             * Logs a formatted message for the specified result.
             * 
             * @param result The test result.
             * @param format Specifies the structure of the log message.
             * @param ... Additional arguments to be formatted into the message.
             */
            static void log(test_result test_result, const char *format, ...);
    };
}

#endif
