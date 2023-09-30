#include "test_reporter.h"

namespace test_framework {
    void test_reporter::list(test_suite test_suite) {
        printf("%s:\n",test_suite.name);
    }

    void test_reporter::list(test_case test_case) {
        printf("    %s\n",test_case.name);
    }

    void test_reporter::announce(std::vector<test_suite> test_suites) {
        size_t n_suites = test_suites.size();
        int n_tests = 0;
        for (test_suite test_suite : test_suites) {
            n_tests += test_suite.test_cases.size();
        }
        log(unknown, "Running %ld tests from %ld files...", n_tests, n_suites);
    }

    void test_reporter::announce(test_suite test_suite) {
        log(unknown, "Running %ld tests from %s:", test_suite.test_cases.size(), test_suite.name);
    }

    void test_reporter::report(test_case test_case) {
        log(passed, "%s:%d:%s", test_case.file_name, test_case.lineno, test_case.name);
    }

    void test_reporter::report(test_case test_case, const char *failure_reason) {
        log(failed, "%s:%d:%s -> %s", test_case.file_name, test_case.lineno, test_case.name, failure_reason);
    }

    void test_reporter::report(test_statistics test_statistics) {
        log(unknown, "%d tests passed, %d tests failed", test_statistics.n_passed, test_statistics.n_failed);
    }

    std::string test_reporter::to_string(test_result test_result) {
        static const std::string reset_color = "\033[0;39m";
        static const std::string red_color = "\033[31m";
        static const std::string green_color = "\033[32m";
        switch (test_result) {
            case test_result::failed: return red_color + "[Failed]" + reset_color;
            case test_result::passed: return green_color + "[Passed]" + reset_color;
            default: return green_color + "[------]" + reset_color;
        }
    }

    void test_reporter::log(test_result test_result, const char *format, ...) {
        va_list args;
        va_start(args, format);
        printf("%s: ", to_string(test_result).c_str());
        vprintf(format, args);
        printf("\n");
        va_end(args);
    }
}
