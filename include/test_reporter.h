#ifndef __YATF_TEST_REPORTER_H__
#define __YATF_TEST_REPORTER_H__

#include <chrono>

#include "test.h"

namespace yatf {
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
            void list(const test_suite &test_suite) const;

            /**
             * Lists the test case.
             * 
             * @param test_case The test case to list.
             */
            void list(const test_case &test_case) const;

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
