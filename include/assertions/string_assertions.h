#ifndef __YATF_STRING_ASSERTIONS_H__
#define __YATF_STRING_ASSERTIONS_H__

#include <string>

#include "basic_assertions.h"

namespace assert {
    /**
     * Provides string assertions for verifying specific conditions within test cases.
     */
    namespace string {
        /**
         * Asserts that a string is empty.
         *
         * @param str The string to check.
         */
        void is_empty(const std::string &str);

        /**
         * Asserts that a string is not empty.
         *
         * @param str The string to check.
         */
        void is_not_empty(const std::string &str);

        /**
         * Asserts that a string is equal to another string.
         *
         * @param str1 The first string to compare.
         * @param str2 The second string to compare.
         */
        void is_equal(const std::string &str1, const std::string &str2);

        /**
         * Asserts that a string is not equal to another string.
         *
         * @param str1 The first string to compare.
         * @param str2 The second string to compare.
         */
        void is_not_equal(const std::string &str1, const std::string &str2);

        /**
         * Asserts that a string starts with a specific prefix.
         *
         * @param str The string to check.
         * @param prefix The expected prefix.
         */
        void starts_with(const std::string &str, const std::string &prefix);

        /**
         * Asserts that a string does not start with a specific prefix.
         *
         * @param str The string to check.
         * @param prefix The prefix that should not be present.
         */
        void does_not_start_with(const std::string &str, const std::string &prefix);

        /**
         * Asserts that a string ends with a specific suffix.
         *
         * @param str The string to check.
         * @param suffix The expected suffix.
         */
        void ends_with(const std::string &str, const std::string &suffix);

        /**
         * Asserts that a string does not end with a specific suffix.
         *
         * @param str The string to check.
         * @param suffix The suffix that should not be present.
         */
        void does_not_end_with(const std::string &str, const std::string &suffix);

        /**
         * Asserts that a string contains a specific substring.
         *
         * @param str The string to check.
         * @param substring The expected substring.
         */
        void contains(const std::string &str, const std::string &substring);

        /**
         * Asserts that a string does not contain a specific substring.
         *
         * @param str The string to check.
         * @param substring The substring that should not be present.
         */
        void does_not_contain(const std::string &str, const std::string &substring);

        /**
         * Asserts that a string matches a specific regular expression pattern.
         *
         * @param str The string to check.
         * @param pattern The regular expression pattern.
         */
        void matches(const std::string &str, const std::string &pattern);

        /**
         * Asserts that a string does not match a specific regular expression pattern.
         *
         * @param str The string to check.
         * @param pattern The regular expression pattern that should not match.
         */
        void does_not_match(const std::string &str, const std::string &pattern);
    }
}

#endif