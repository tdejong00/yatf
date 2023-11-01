#include <iostream>
#include <iomanip>

#include "test_reporter.h"

namespace yatf {
    const int MILLISECONDS_PRECISION = 6;
    const int MILLISECONDS_RATIO = 1000;

    std::ostream&operator<<(std::ostream &stream, const color &color) {
        switch (color) {
            case RED:
                return stream << "\033[31m";
            case GREEN:
                return stream << "\033[32m";
            case ORANGE:
                return stream << "\033[33m";
            case GRAY:
                return stream << "\033[90m";
            default:
                return stream << "\033[0;39m";
        }
    }

    test_reporter::test_reporter() : options({ false, true }) {}

    test_reporter::test_reporter(const report_options &options) : options(options) {}

    std::ostream &operator<<(std::ostream &stream, const test_result &test_result) {
        switch (test_result) {
            case FAILED: return stream << RED << "FAIL: " << RESET;
            case PASSED: return stream << GREEN << "OK:   " << RESET;
            default: return stream << ORANGE;
        }
    }

    test_statistics operator-(const test_statistics &first, const test_statistics &second) {
        return {
            first.total_count - second.total_count, 
            first.passed_count - second.passed_count, 
            first.failed_count - second.failed_count
        };
    }

    std::ostream &operator<<(std::ostream &stream, const test_statistics &test_statistics) {
        return stream << (test_statistics.failed_count > 0 ? RED : GREEN)
            << test_statistics.passed_count << (test_statistics.passed_count == 1 ? " test " : " tests ") << "passed, "
            << test_statistics.failed_count << (test_statistics.failed_count == 1 ? " test " : " tests ") << "failed";
    }

    std::ostream &operator<<(std::ostream &stream, const std::chrono::duration<double> &duration) {
        return stream << "(" << std::fixed << std::setprecision(MILLISECONDS_PRECISION)
            << duration.count() * MILLISECONDS_RATIO << " ms)";
    }

    void test_reporter::message(const std::string &message) {
        std::cout << GRAY << "INFO: " << message << RESET << std::endl;
    }

    void test_reporter::list(const test_suite &test_suite) {
        std::cout << test_suite << std::endl;
    }

    void test_reporter::list(const test_case &test_case) {
        std::cout << test_case << std::endl;
    }

    void test_reporter::announce_test_suite(const test_suite &test_suite) const {
        const size_t n_tests = test_suite.test_cases.size();
        std::cout << UNKNOWN << "Running " << n_tests << " "
            << (n_tests == 1 ? "test" : "tests") << " from " << test_suite << std::endl;
    }

    void test_reporter::report_test_case(const test_case &test_case, const test_result &test_result, const std::chrono::duration<double> &duration, const std::string &reason) const {
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
                    std::cerr << " " << duration;
                }
                if (!reason.empty()) {
                    std::cerr << " --> " << RED << reason << RESET;
                }
                std::cout << std::endl;
                break;
            default:
                std::cerr << RED << "error: unknown test result" << RESET << std::endl;
                break;
        }
    }

    void test_reporter::report_test_suite(const test_statistics &test_statistics, const std::chrono::duration<double> &duration) const {
        std::cout << UNKNOWN << test_statistics;
        if (options.show_execution_times) {
            std::cout << " " << duration;
        }
        std::cout << std::endl;
    }
}
