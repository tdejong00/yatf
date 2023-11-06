#include <regex>

#include "assertions/string_assertions.h"

namespace assert {
    namespace string {
        void is_empty(const std::string &str) {
            if (!str.empty()) {
                throw assertion_failed("expected string to be empty, but it was not");
            }
        }

        void is_not_empty(const std::string &str) {
            if (str.empty()) {
                throw assertion_failed("expected string to not be empty, but it was");
            } 
        }

        void is_equal(const std::string& str1, const std::string& str2) {
            if (str1 != str2) {
                throw assertion_failed("expected strings to be equal, but they were not");
            }
        }

        void is_not_equal(const std::string &str1, const std::string &str2) {
            if (str1 == str2) {
                throw assertion_failed("expected strings to not be equal, but they were");
            }
        }

        void starts_with(const std::string& str, const std::string& prefix) {
            if (str.size() < prefix.size() || str.substr(0, prefix.size()) != prefix) {
                throw assertion_failed("expected string to start with the specified prefix, but it did not");
            }
        }

        void does_not_start_with(const std::string& str, const std::string& prefix) {
            if (str.size() >= prefix.size() && str.substr(0, prefix.size()) == prefix) {
                throw assertion_failed("expected string to not start with the specified prefix, but it did");
            }
        }

        void ends_with(const std::string& str, const std::string& suffix) {
            if (str.size() < suffix.size() || str.substr(str.size() - suffix.size()) != suffix) {
                throw assertion_failed("expected string to end with the specified suffix, but it did not");
            }
        }

        void does_not_end_with(const std::string& str, const std::string& suffix) {
            if (str.size() >= suffix.size() && str.substr(str.size() - suffix.size()) == suffix) {
                throw assertion_failed("expected string to not end with the specified suffix, but it did");
            }
        }

        void contains(const std::string& str, const std::string& substring) {
            if (str.find(substring) == std::string::npos) {
                throw assertion_failed("expected string to contain the specified substring, but it did not");
            }
        }

        void does_not_contain(const std::string& str, const std::string& substring) {
            if (str.find(substring) != std::string::npos) {
                throw assertion_failed("expected string to not contain the specified substring, but it did");
            }
        }

        void matches(const std::string& str, const std::string& pattern) {
            if (!std::regex_match(str, std::regex(pattern))) {
                throw assertion_failed("expected string to match the specified pattern, but it did not");
            }
        }

        void does_not_match(const std::string& str, const std::string& pattern) {
            if (std::regex_match(str, std::regex(pattern))) {
                throw assertion_failed("expected string to not match the specified pattern, but it did");
            }
        }
    }
}
