#include <string>
#include <chrono>

#include "test_runner.h"
#include "test_registry.h"
#include "assertions/basic_assertions.h"

namespace yatf {
    /**
     * Calculates the elapsed time since the given time point.
     * 
     * @param time_point The time point for which to calculate to elapsed time.
     * @return The elapsed time in seconds.
     */
    inline std::chrono::duration<double> elapsed_time(const std::chrono::high_resolution_clock::time_point &time_point) {
        return std::chrono::high_resolution_clock::now() - time_point;
    }

    test_runner::test_runner() : statistics({0, 0, 0}) {}

    test_runner::test_runner(const report_options &options) : reporter(test_reporter(options)), statistics({0, 0, 0}) {}

    bool test_runner::run_test_suite(const std::string &test_suite_name) {
        test_suite *test_suite = test_registry::find_test_suite(test_suite_name);
        if (test_suite == nullptr) {
            return false;
        }
        run_test_suite(*test_suite);
        return true;
    }

    void test_runner::run_all_tests() {
        for (const test_suite &test_suite : test_registry::get_test_suites()) {
            run_test_suite(test_suite);
        }
    }

    void test_runner::list_all_tests() const {
        for (const test_suite &test_suite : test_registry::get_test_suites()) {
            reporter.list(test_suite);
            for (const test_case &test_case : test_suite.test_cases) {
                reporter.list(test_case);
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

        reporter.report_test_suite(after - before, elapsed_time(time_point));
    }

    void test_runner::run_test_case(const test_case &test_case) {
        auto time_point = std::chrono::high_resolution_clock::now();

        try {
            test_case.function();
        }
        /* Assertion explicitly passed */
        catch (const assert::assertion_passed &e) { }
        /* Assertion failed */
        catch (const assert::assertion_failed &e) {
            statistics.failed_count++;
            statistics.total_count++;
            reporter.report_test_case(test_case, test_result::FAILED, elapsed_time(time_point), e.what());
            return;
        }
        /* Unexpected exception */
        catch (...) {
            statistics.failed_count++;
            statistics.total_count++;
            reporter.report_test_case(test_case, test_result::FAILED, elapsed_time(time_point), "unexpected exception caught");
            return;
        }

        /* Assertion passed */
        statistics.passed_count++;
        statistics.total_count++;
        reporter.report_test_case(test_case, test_result::PASSED, elapsed_time(time_point));
    }
}
