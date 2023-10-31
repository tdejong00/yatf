#include <iostream>
#include <cstring>
#include <chrono>

#include "test_runner.h"

namespace yatf {
    /**
     * @brief Calculates the elapsed time since the given time point.
     * 
     * @param time_point The time point for which to calculate to elapsed time.
     * @return The elapsed time in seconds.
     */
    inline std::chrono::duration<double> elapsed_time(const std::chrono::high_resolution_clock::time_point &time_point) {
        return std::chrono::high_resolution_clock::now() - time_point;
    }

    test_runner::test_runner() : statistics({0, 0, 0}) {}

    test_runner::test_runner(const report_options &options) : reporter(test_reporter(options)), statistics({0, 0, 0}) {}

    bool test_runner::run_test_suite(const char *test_suite_name) {
        test_suite *test_suite = test_registry::find_test_suite(test_suite_name);
        if (test_suite == nullptr) {
            return false;
        }
        run_test_suite(*test_suite);
        return true;
    }

    void test_runner::run_all_tests() {
        auto time_point = std::chrono::high_resolution_clock::now();

        reporter.announce_test_module(test_registry::get_test_suites());

        for (const test_suite &test_suite : test_registry::get_test_suites()) {
            run_test_suite(test_suite);
        }

        reporter.report_test_module(statistics, elapsed_time(time_point));
    }

    void test_runner::list_all_tests()
    {
        for (const test_suite &test_suite : test_registry::get_test_suites()) {
            test_reporter::list(test_suite);
            for (const test_case &test_case : test_suite.test_cases) {
                test_reporter::list(test_case);
            }
        }
    }

    void test_runner::run_test_suite(const test_suite &test_suite) {
        auto time_point = std::chrono::high_resolution_clock::now();
        
        reporter.announce_test_suite(test_suite);
        
        const test_statistics before = statistics;
        for (const test_case &test_case : test_suite.test_cases) {
            run_test_case(test_case);
        }
        const test_statistics after = statistics;

        reporter.report_test_suite(test_suite, after - before, elapsed_time(time_point));
    }

    void test_runner::run_test_case(const test_case &test_case) {
        auto time_point = std::chrono::high_resolution_clock::now();
        
        try {
            test_case.function();
        }
        catch (const assert::assertion_error &e) {
            statistics.failed_count++;
            statistics.total_count++;
            reporter.report_test_case(test_case, FAILED, elapsed_time(time_point), e.what());
            return;
        }
        statistics.passed_count++;
        statistics.total_count++;
        reporter.report_test_case(test_case, PASSED, elapsed_time(time_point));
    }
}
