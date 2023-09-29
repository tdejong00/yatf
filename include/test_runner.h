#ifndef __TEST_RUNNER_H__
#define __TEST_RUNNER_H__

#include <vector>

/**
 * @brief Testing framework containing registering and running tests cases or test suites.
 */
namespace test_framework {
    /**
     * @brief A test case within a test suite.
     * 
     * Consists of a human-readable name and a function pointer to the actual test code.
     */
    struct test_case {
        const char *name; /* Name of the test case. */
        const char *file_name; /* Name of the file where the test is located. */
        int lineno; /* Number of the line where the test is located. */
        void (*function)(); /* Function pointer to the test case function. */
    };

    /**
     * @brief A container for grouping multiple test cases.
     * 
     * Consists of a human-readable name and a collection of test cases.
     */
    struct test_suite {
        const char *name; /* Name of the test suite. */
        std::vector<test_case> test_cases; /* Collection of test cases within the test suite. */
    };

    /**
     * @brief Registers and runs test cases or test suites.
     * 
     * Provides a framework for organizing and executing test cases within a testing environment. 
     * It allows you to register individual test cases and then execute them as a group. This class 
     * follows a static design pattern, meaning you don't need to create instances of it; you interact 
     * with it using static methods.
     */
    class test_runner {
        public:
            test_runner() = delete;
            ~test_runner() = delete;

            /**
             * @brief Registers the test case in the test suite with the given name.
             * 
             * @param test_suite_name The name of the test suite to register the test case in.
             * @param test_case The test case to register.
             */
            static void register_test_case(const char *test_suite_name, test_case test_case);

            /**
             * @brief Runs all registered test cases.
             * 
             */
            static void run_all_tests();

        private:
            /**
             * @brief Finds the test suite with the given name
             * 
             * @param name The name of the test suite.
             * @return A pointer to the test suite, or nullptr if not found.
             */
            static test_suite *find_test_suite(const char *test_suite_name);

            /**
             * @brief Registers a test suite.
             * 
             * @param test_suite The name of the test suite.
             */
            static test_suite *register_test_suite(const char *test_suite_name);

            /**
             * @brief Runs a specific test suite.
             * 
             * @param test_suite The test suite to run.
             */
            static void run_test_suite(test_suite test_suite);

            /**
             * @brief Runs a specific test case.
             * 
             * @param test_case The test case to run.
             */
            static void run_test_case(test_case test_case);

            static std::vector<test_suite> test_suites;
            static int n_total, n_passed, n_failed;
    };
}

#endif
