#include <iostream>
#include <iomanip>

#include "test_reporter.h"

namespace test_framework {
    const constexpr char *RESET_COLOR = "\033[0;39m";
    const constexpr char *RED_COLOR = "\033[31m";
    const constexpr char *GREEN_COLOR = "\033[32m";
    const constexpr char *ORANGE_COLOR = "\033[33m";

    test_reporter::test_reporter(report_options options) : options(options) { }

    std::ostream &operator<<(std::ostream &os, test_result test_result)
    {
        switch (test_result) {
            case FAILED: return os << RED_COLOR << "FAIL: " << RESET_COLOR;
            case PASSED: return os << GREEN_COLOR << "OK: " << RESET_COLOR;
            default: return os << ORANGE_COLOR;
        }
    }

    test_statistics operator-(test_statistics first, test_statistics second) {
        return {
            first.total_count - second.total_count, 
            first.passed_count - second.passed_count, 
            first.failed_count - second.failed_count
        };
    }

    std::ostream &operator<<(std::ostream &os, test_statistics test_statistics) {
        return os << (test_statistics.failed_count > 0 ? RED_COLOR : GREEN_COLOR) 
            << test_statistics.passed_count << (test_statistics.passed_count == 1 ? " test " : " tests ") << "passed, "
            << test_statistics.failed_count << (test_statistics.failed_count == 1 ? " test " : " tests ") << "failed";
    }

    std::ostream &operator<<(std::ostream &os, std::chrono::duration<double> duration) {
        return os << "(" << std::fixed << std::setprecision(6) << duration.count() * 1000 << " ms)";
    }

    void test_reporter::list(test_suite test_suite) {
        std::cout << test_suite << std::endl;
    }

    void test_reporter::list(test_case test_case) {
        std::cout << test_case << std::endl;
    }

    void test_reporter::announce_test_module(std::vector<test_suite> test_suites) {
        if (options.is_verbose) {
            size_t n_suites = test_suites.size();
            size_t n_tests = 0;
            for (test_suite test_suite : test_suites) {
                n_tests += test_suite.test_cases.size();
            }

            std::cout << UNKNOWN << "Running " << n_tests << " "
                << (n_tests == 1 ? "test" : "tests") << " from " << n_suites << " "
                << (n_suites == 1 ? "suite" : "suites") << "..." << std::endl;
        }
    }

    void test_reporter::announce_test_suite(test_suite test_suite) {
        if (options.is_verbose) {
            size_t n_tests = test_suite.test_cases.size();
            std::cout << UNKNOWN << "Running " << n_tests << " "
                << (n_tests == 1 ? "test" : "tests") << " from " << test_suite << std::endl;
        }
    }

    void test_reporter::report_test_case(test_case test_case, test_result test_result, std::chrono::duration<double> duration, const char *failure_reason) {
        switch (test_result) {
            case PASSED:
                if (options.show_passed_tests) {
                    std::cout << PASSED << test_case;
                    if (options.show_execution_times) {
                        std::cout << " " << duration;
                    }
                    std::cout << std::endl;
                }
                break;
            case FAILED:
                std::cerr << FAILED << test_case;
                if (options.show_execution_times) {
                    std::cout << " " << duration;
                }
                std::cout << " --> " << RED_COLOR << failure_reason << RESET_COLOR << std::endl;
                break;
            default:
                std::cerr << RED_COLOR << "error: unknown test result" << RESET_COLOR << std::endl;
                break;
        }
    }

    void test_reporter::report_test_suite(test_suite test_suite, test_statistics test_statistics, std::chrono::duration<double> duration) {
        if (options.is_verbose) {
            size_t n_tests = test_suite.test_cases.size();
            std::cout << UNKNOWN << "Ran " << n_tests << " " 
                << (n_tests == 1 ? "test" : "tests") << " from " << test_suite << " " << test_statistics;
            if (options.show_execution_times) {
                std::cout << " " << duration;
            }
            std::cout << std::endl;
        }
    }

    void test_reporter::report_test_module(test_statistics test_statistics, std::chrono::duration<double> duration) {
        if (options.is_verbose) {
            std::cout << UNKNOWN << test_statistics;
            if (options.show_execution_times) {
                std::cout << " " << duration;
            }
            std::cout << std::endl;
        }
    }
}
