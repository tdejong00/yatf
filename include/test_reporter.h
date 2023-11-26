#ifndef __YATF_TEST_REPORTER_H__
#define __YATF_TEST_REPORTER_H__

#include <cstdarg>
#include <vector>
#include <chrono>

#include "test_registry.h"

namespace yatf {
    /**
     * Represents different terminal colors.
     */
    enum color { RED, GREEN, ORANGE, GRAY, RESET };

    /**
     * Streams a color to an output stream.
     * 
     * @param stream The output stream to stream to.
     * @param color The color to stream.
     * @return A reference to the output stream after streaming the color.
     */
    std::ostream &operator<<(std::ostream &stream, const color &color);

    /**
     * Represents the result of a test case.
     */
    enum test_result { UNKNOWN, FAILED, PASSED };

    /**
     * Streams a test result to an output stream.
     * 
     * @param stream The output stream to stream to.
     * @param report_level The test result to stream.
     * @return A reference to the output stream after streaming the test result.
     */
    std::ostream &operator<<(std::ostream &stream, const test_result &test_result);

    /**
     * A container for storing the test results.
     */
    struct test_statistics {
        int total_count; /* Total amount of test cases. */
        int passed_count; /* Number of passed test cases. */
        int failed_count; /* Number of failed test cases. */

        /**
         * Calculates the difference between two test statistics.
         * 
         * @param first The first test statistics.
         * @param second The second test statistics.
         * @return The difference between the two test statistics.
         */
        friend test_statistics operator-(const test_statistics &first, const test_statistics &second);

        /**
         * Streams test statistics to an output stream.
         *
         * @param stream The output stream to stream to.
         * @param test_statistics The test statistics to stream.
         * @return A reference to the output stream after streaming the test statistics.
         */
        friend std::ostream &operator<<(std::ostream &stream, const test_statistics &test_statistics);
    };

    /**
     * Represents the different output options for the test announcements and reports.
     */
    struct report_options {
        bool show_execution_times; /* Whether to show execution times in the test reports. */
        bool show_passed_tests; /* Whether to show reports for passed tests. */
    };

    /**
     * Streams a duration to an output stream.
     * 
     * @param stream The output stream to stream to.
     * @param duration The elapsed time in seconds to stream.
     * @return A reference to the output stream after streaming the duration.
     */
    std::ostream &operator<<(std::ostream &stream, const std::chrono::duration<double> &duration);

    /**
     * Provides functionality for announcing tests and reporting test results.
     */
    class test_reporter {
        public:
            /**
             * Constructs a new instance of the test reporter using the default report options.
             */
            test_reporter();

            /**
             * Constructs a new instance of the test reporter using the given report options.
             * 
             * @param options Options for controlling the announcements and reports.
             */
            test_reporter(const report_options &options);

            /**
             * Displays a message.
             * 
             * @param message The message to display.
             */
            static void message(const std::string &message);

            /**
             * Lists the test suite.
             * 
             * @param test_suite The test suite to list.
             */
            static void list(const test_suite &test_suite);

            /**
             * Lists the test case.
             * 
             * @param test_case The test case to list.
             */
            static void list(const test_case &test_case);

            /**
             * Announces a single test suite.
             * 
             * @param test_suite The test suite to announce.
             */
            void announce_test_suite(const test_suite &test_suite) const;

            /**
             * Reports the failure of a test case.
             * 
             * @param test_case The test case to report.
             * @param test_result The result of the test case.
             * @param duration The elapsed time in seconds.
             * @param reason Reason for why the test case has failed or passed.
             */
            void report_test_case(const test_case &test_case, const test_result &test_result, const std::chrono::duration<double> &duration, const std::string &reason = "") const;

            /**
             * Reports the results of the whole test suite.
             *
             * @param test_statistics The statistics for the executed tests.
             * @param duration The elapsed time in seconds.
             */
            void report_test_suite(const test_statistics &statistics, const std::chrono::duration<double> &duration) const;

        private:
            report_options options;
    };
}

#endif
