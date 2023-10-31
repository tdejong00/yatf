#ifndef __YATF_TEST_REPORTER_H__
#define __YATF_TEST_REPORTER_H__

#include <cstdarg>
#include <vector>
#include <chrono>

#include "test_registry.h"

namespace yatf {
    /**
     * @brief Represents the result of a test case.
     */
    enum test_result {
        UNKNOWN, /* The result has not been set. */
        FAILED, /* The test case has failed. */
        PASSED /* The test case has passed. */
    };

    /**
     * @brief Streams a test result to an output stream.
     * 
     * @param stream The output stream to stream to.
     * @param report_level The test result to stream.
     * @return A reference to the output stream after streaming the test result.
     */
    std::ostream &operator<<(std::ostream &stream, const test_result &test_result);

    /**
     * @brief A container for storing the test results.
     */
    struct test_statistics {
        int total_count; /* Total amount of test cases. */
        int passed_count; /* Number of passed test cases. */
        int failed_count; /* Number of failed test cases. */

        /**
         * @brief Calculates the difference between two test statistics.
         * 
         * @param first The first test statistics.
         * @param second The second test statistics.
         * @return The difference between the two test statistics.
         */
        friend test_statistics operator-(const test_statistics &first, const test_statistics &second);

        /**
         * @brief Streams test statistics to an output stream.
         *
         * @param stream The output stream to stream to.
         * @param test_statistics The test statistics to stream.
         * @return A reference to the output stream after streaming the test statistics.
         */
        friend std::ostream &operator<<(std::ostream &stream, const test_statistics &test_statistics);
    };

    /**
     * @brief Represents the different output options for the test announcements and reports.
     */
    struct report_options {
        bool is_verbose; /* Whether the report output should be verbose. */
        bool show_execution_times; /* Whether to show execution times in the test reports. */
        bool show_passed_tests; /* Whether to show reports for passed tests. */
    };

    /**
     * @brief Streams a duration to an output stream.
     * 
     * @param stream The output stream to stream to.
     * @param duration The duration to stream.
     * @return A reference to the output stream after streaming the duration.
     */
    std::ostream &operator<<(std::ostream &stream, const std::chrono::duration<double> &duration);

    /**
     * @brief Provides functionality for announcing tests and reporting test results.
     */
    class test_reporter {
        public:
            /**
             * @brief Constructs a new instance of the test reporter using the default report options.
             */
            test_reporter();

            /**
             * @brief Constructs a new instance of the test reporter using the given report options.
             * 
             * @param options Options for controlling the announcements and reports.
             */
            test_reporter(const report_options &options);

            /**
             * @brief Lists the test suite.
             * 
             * @param test_suite The test suite to list.
             */
            static void list(const test_suite &test_suite);

            /**
             * @brief Lists the test case.
             * 
             * @param test_case The test case to list.
             */
            static void list(const test_case &test_case);

            /**
             * @brief Announces all test suites.
             * 
             * @param suites A list of test suites to announce.
             */
            void announce_test_module(const std::vector<test_suite> &suites) const;

            /**
             * @brief Announces a single test suite.
             * 
             * @param test_suite The test suite to announce.
             */
            void announce_test_suite(const test_suite &test_suite) const;

            /**
             * @brief Reports the failure of a test case.
             * 
             * @param test_case The test case to report.
             * @param test_result The result of the test case.
             * @param duration The elapsed time in seconds.
             * @param failure_reason Reason for why the test case has failed.
             */
            void report_test_case(const test_case &test_case, const test_result &test_result, const std::chrono::duration<double> &duration, const char *failure_reason = "") const;

            /**
             * @brief Reports the results of the whole test suite.
             * 
             * @param test_suite The test suite to report.
             * @param test_statistics The statistics for the executed tests.
             * @param duration The elapsed time in seconds.
             */
            void report_test_suite(const test_suite &test_suite, const test_statistics &statistics, const std::chrono::duration<double> &duration) const;

            /**
             * @brief Reports the result of all test cases.
             * 
             * @param statistics The statistics for the executed tests.
             * @param duration The elapsed time in seconds.
             */
            void report_test_module(const test_statistics &statistics, const std::chrono::duration<double> &duration) const;

        private:
            report_options options;
    };
}

#endif
