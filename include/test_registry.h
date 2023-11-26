#ifndef __YATF_TEST_REGISTRY_H__
#define __YATF_TEST_REGISTRY_H__

#include <string>
#include <vector>

#include "test.h"

namespace yatf {
    /**
     * Manages and stores test cases for the testing framework.
     */
    class test_registry {
        public:
            test_registry() = delete;

            /**
             * Retrieves all registered test suites.
             * 
             * @return A vector containing all registered test suites.
             */
            static std::vector<test_suite> get_test_suites();

            /**
             * Retrieves all registered test cases.
             * 
             * @return A vector containing all registered test cases.
             */
            static std::vector<test_case> get_test_cases();

            /**
             * Registers a test suite.
             * 
             * @param suite_name The name of the test suite.
             */
            static test_suite *register_test_suite(const std::string &suite_name);

            /**
             * Registers the test case in the test suite with the given name.
             * 
             * @param suite_name The name of the test suite to register the test case in.
             * @param test_case The test case to register.
             */
            static void register_test_case(const std::string &suite_name, const test_case &test_case);

            /**
             * Finds the test suite with the given name
             * 
             * @param suite_name The name of the test suite.
             * @return A pointer to the test suite, or nullptr if not found.
             */
            static test_suite *find_test_suite(const std::string &suite_name);

            /**
             * Finds the test case with the given name
             * 
             * @param suite_name The name of the test suite.
             * @param case_name The name of the test case.
             * @return A pointer to the test case, or nullptr if not found.
             */
            static test_case *find_test_case(const std::string &suite_name, const std::string &case_name);

        private:
            static std::vector<test_suite> test_suites;
            static std::vector<test_case> test_cases;
    };
}

#endif
