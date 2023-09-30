#include "test_runner.h"
#include "test_reporter.h"
#include "test_assert.h"

#include <cstring>

namespace test_framework {
    std::vector<test_suite> test_runner::test_suites;
    int test_runner::n_total, test_runner::n_passed, test_runner::n_failed;

    void test_runner::register_test_case(const char *test_suite_name, test_case test_case) {
        test_suite *test_suite = find_test_suite(test_suite_name);
        if (test_suite == nullptr) {
            test_suite = register_test_suite(test_suite_name);
        }
        test_suite->test_cases.push_back(test_case);
        n_total++;
    }

    test_suite *test_runner::register_test_suite(const char *test_suite_name) {
        test_suites.push_back({ test_suite_name, {}});
        return &test_suites.back();
    }

    void test_runner::run_all_tests() {
        test_reporter::announce(test_suites);
        for (test_suite test_suite : test_suites) {
            run_test_suite(test_suite);
        }
        test_reporter::report({ n_passed + n_failed, n_passed, n_failed });
    }

    void test_runner::list_all_tests()
    {
        for (test_suite test_suite : test_suites) {
            test_reporter::list(test_suite);
            for (test_case test_case : test_suite.test_cases) {
                test_reporter::list(test_case);
            }
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

    void test_runner::run_test_suite(test_suite test_suite) {
        test_reporter::announce(test_suite);
        for (test_case t : test_suite.test_cases) {
            run_test_case(t);
        }
    }

    void test_runner::run_test_case(test_case test_case) {
        try {
            test_case.function();
        }
        catch (assertion_error &e) {
            n_failed++;
            test_reporter::report(test_case, e.what());
            return;
        }
        n_passed++;
        test_reporter::report(test_case);
    }
}
