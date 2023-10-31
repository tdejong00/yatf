#include <cstring>

#include "test_registry.h"

namespace yatf {
    std::vector<test_suite> test_registry::test_suites;
    std::vector<test_case> test_registry::test_cases;

    std::ostream &operator<<(std::ostream &stream, const test_case &test_case) {
        return stream << test_case.file_name << ":" << test_case.name;
    }

    std::ostream &operator<<(std::ostream &stream, const test_suite &test_suite) {
        return stream << test_suite.name << ":";
    }

    std::vector<test_suite> test_registry::get_test_suites() {
        return test_suites;
    }

    std::vector<test_case> test_registry::get_test_cases() {
        return test_cases;
    }

    test_suite *test_registry::register_test_suite(const char *test_suite_name) {
        test_suites.push_back({ test_suite_name, {}});
        return &test_suites.back();
    }

    void test_registry::register_test_case(const char *test_suite_name, const test_case &test_case) {
        test_suite *test_suite = find_test_suite(test_suite_name);
        if (test_suite == nullptr) {
            test_suite = register_test_suite(test_suite_name);
        }
        test_suite->test_cases.push_back(test_case);
        test_cases.push_back(test_case);
    }

    test_suite *test_registry::find_test_suite(const char *test_suite_name) {
        for (test_suite &test_suite : test_suites) {
            if (std::strcmp(test_suite_name, test_suite.name) == 0) {
                return &test_suite;
            }
        }
        return nullptr;
    }

    test_case *test_registry::find_test_case(const char *test_suite_name, const char *test_case_name) {
        test_suite *test_suite = find_test_suite(test_suite_name);
        if (test_suite != nullptr) {
            for (test_case &test_case : test_suite->test_cases) {
                if (std::strcmp(test_case_name, test_case.name) == 0) {
                    return &test_case;
                }
            }
        }
        return nullptr;
    }
}
