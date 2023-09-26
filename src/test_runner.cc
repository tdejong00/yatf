#include "test_runner.h"

#include <cstring>

namespace test_framework {
    std::vector<test_suite> test_runner::test_suites;
    std::vector<test_case> test_runner::test_cases;

    void test_runner::register_test(test_case test_case) {
        test_cases.push_back(test_case);
    }

    void test_runner::register_test(const char *test_suite_name, test_case test_case) {
        test_suite *test_suite = find_test_suite(test_suite_name);
        if (test_suite == nullptr) {
            test_suite = register_test_suite(test_suite_name);
        }
        test_suite->test_cases.push_back(test_case);
    }

    test_suite *test_runner::register_test_suite(const char *test_suite_name) {
        test_suites.push_back({ test_suite_name, {}});
        return &test_suites.back();
    }

    void test_runner::run_test_suites() {
        for (test_suite test_suite : test_suites) {
            for (test_case test_case : test_suite.test_cases) {
                test_case.function();
            }
        }
    }

    void test_runner::run_tests() {
        for (test_case test_case : test_cases) {
            test_case.function();
        }
    }

    test_suite *test_runner::find_test_suite(const char *test_suite_name) {
        for (test_suite &test_suite : test_suites) {
            if (std::strcmp(test_suite_name, test_suite.name) == 0) {
                return &test_suite;
            }
        }
        return nullptr;
    }
}
