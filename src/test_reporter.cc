#include <iostream>

#include "test_reporter.h"

namespace yatf {
    test_reporter::test_reporter() : options({ false, true }) {}

    test_reporter::test_reporter(const report_options &options) : options(options) {}

    void test_reporter::message(const std::string &message) {
        std::cout << color::GRAY << "INFO: " << message << color::RESET << std::endl;
    }

    void test_reporter::list(const test_suite &test_suite) const {
        std::cout << test_suite << std::endl;
    }

    void test_reporter::list(const test_case &test_case) const {
        std::cout << test_case << std::endl;
    }

    void test_reporter::announce_test_suite(const test_suite &test_suite) const {
        const size_t n_tests = test_suite.test_cases.size();
        std::cout << test_result::UNKNOWN << "Running " << n_tests << " "
            << (n_tests == 1 ? "test" : "tests") << " from " << test_suite << std::endl;
    }

    void test_reporter::report_test_case(const test_case &test_case, const test_result &test_result, const std::chrono::duration<double> &duration, const std::string &reason) const {
        switch (test_result) {
            case test_result::PASSED:
                if (options.show_passed_tests) {
                    std::cout << test_result::PASSED << test_case;
                    if (options.show_execution_times) {
                        std::cout << " " << duration;
                    }
                    std::cout << std::endl;
                }
                break;
            case test_result::FAILED:
                std::cerr << test_result::FAILED << test_case;
                if (options.show_execution_times) {
                    std::cerr << " " << duration;
                }
                if (!reason.empty()) {
                    std::cerr << " --> " << color::RED << reason << color::RESET;
                }
                std::cout << std::endl;
                break;
            default:
                std::cerr << color::RED << "error: unknown test result" << color::RESET << std::endl;
                break;
        }
    }

    void test_reporter::report_test_suite(const test_statistics &test_statistics, const std::chrono::duration<double> &duration) const {
        std::cout << test_result::UNKNOWN << test_statistics;
        if (options.show_execution_times) {
            std::cout << " " << duration;
        }
        std::cout << std::endl;
    }
}
