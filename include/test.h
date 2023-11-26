#ifndef __TEST_H__
#define __TEST_H__

#include <string>
#include <vector>
#include <functional>
#include <ostream>
#include <chrono>

namespace yatf {
    /**
     * A test case within a test suite. Consists of a human-readable 
     * name and a function pointer to the actual test code.
     */
    struct test_case {
        const std::string name; /* Name of the test case. */
        const std::string file_name; /* Name of the file where the test is located. */
        int lineno; /* Number of the line where the test is located. */
        std::function<void()> function; /* Function pointer to the test case function. */

        /**
         * Streams a test case to an output stream.
         * 
         * @param stream The output stream to stream to.
         * @param test_case The test case to stream.
         * @return A reference to the output stream after streaming the test case.
         */
        friend std::ostream &operator<<(std::ostream &stream, const test_case &test_case);
    };
    
    /**
     * A container for grouping multiple test cases. Consists 
     * of a human-readable name and a collection of test cases.
     */
    struct test_suite {
        const std::string name; /* Name of the test suite. */
        std::vector<test_case> test_cases; /* Collection of test cases within the test suite. */

        /**
         * Streams a test suite to an output stream.
         * 
         * @param stream The output stream to stream to.
         * @param test_suite The test suite to stream.
         * @return A reference to the output stream after streaming the test suite.
         */
        friend std::ostream &operator<<(std::ostream &stream, const test_suite &test_suite);
    };

    /**
     * Represents the result of a test case.
     */
    enum class test_result { UNKNOWN, FAILED, PASSED };

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
     * Represents different terminal colors.
     */
    enum class color { RED, GREEN, ORANGE, GRAY, RESET };

    /**
     * Streams a color to an output stream.
     * 
     * @param stream The output stream to stream to.
     * @param color The color to stream.
     * @return A reference to the output stream after streaming the color.
     */
    std::ostream &operator<<(std::ostream &stream, const color &color);

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
}

#endif