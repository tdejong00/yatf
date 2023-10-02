#ifndef __TEST_REGISTRY_H__
#define __TEST_REGISTRY_H__

#include <vector>
#include <ostream>

/**
 * @brief The root namespace for YATF.
 *
 * This namespace contains all the components and utilities necessary for creating,
 * registering, and running tests, as well as reporting their results. The framework
 * includes an assertion library, a static test registry for compile-time test
 * registration, a test runner for executing registered tests at runtime, and a
 * test reporter for displaying test outcomes. Additionally, it provides macros for
 * easily registering tests and performing assertions within test cases.
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

        /**
         * @brief Streams a test case to an output stream.
         * 
         * @param os The output stream to stream to.
         * @param tc The test case to stream.
         * @return A reference to the output stream after streaming the test case.
         */
        friend std::ostream &operator<<(std::ostream &os, test_case test_case);
    };
    
    /**
     * @brief A container for grouping multiple test cases.
     * 
     * Consists of a human-readable name and a collection of test cases.
     */
    struct test_suite {
        const char *name; /* Name of the test suite. */
        std::vector<test_case> test_cases; /* Collection of test cases within the test suite. */

        /**
         * @brief Streams a test suite to an output stream.
         * 
         * @param os The output stream to stream to.
         * @param test_suite The test suite to stream.
         * @return A reference to the output stream after streaming the test suite.
         */
        friend std::ostream &operator<<(std::ostream &os, test_suite test_suite);
    };

    /**
     * @brief Manages and stores test cases for the testing framework.
     */
    class test_registry {
        public:
            /**
             * @brief Retrieves all registered test suites.
             * 
             * @return A vector containing all registered test suites.
             */
            static const std::vector<test_suite> get_test_suites();

            /**
             * @brief Retrieves all registered test cases.
             * 
             * @return A vector containing all registered test cases.
             */
            static const std::vector<test_case> get_test_cases();

            /**
             * @brief Registers a test suite.
             * 
             * @param suite_name The name of the test suite.
             */
            static test_suite *register_test_suite(const char *suite_name);

            /**
             * @brief Registers the test case in the test suite with the given name.
             * 
             * @param suite_name The name of the test suite to register the test case in.
             * @param test_case The test case to register.
             */
            static void register_test_case(const char *suite_name, test_case test_case);

            /**
             * @brief Finds the test suite with the given name
             * 
             * @param suite_name The name of the test suite.
             * @return A pointer to the test suite, or nullptr if not found.
             */
            static test_suite *find_test_suite(const char *suite_name);

            /**
             * @brief Finds the test case with the given name
             * 
             * @param suite_name The name of the test suite.
             * @param case_name The name of the test case.
             * @return A pointer to the test case, or nullptr if not found.
             */
            static test_case *find_test_case(const char *suite_name, const char *case_name);

        private:
            static std::vector<test_suite> test_suites;
            static std::vector<test_case> test_cases;
    };
}

#endif