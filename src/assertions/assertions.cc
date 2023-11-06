#include "assertions/assertions.h"
#include "test_reporter.h"

namespace assert {
    void fail(const std::string &message) {
        if (message.empty()) {
            throw assertion_failed();
        }   
        throw assertion_failed(message);
    }

    void pass(const std::string &message) {
        if (message.empty()) {
            throw assertion_passed();
        }        
        throw assertion_passed(message);
    }

    void message(const std::string &message) {
        yatf::test_reporter::message(message);
    }

    void is_true(const bool &condition) {
        if (!condition) {
            throw assertion_failed("expected condition to be true, but it was not");
        }
    }

    void is_false(const bool &condition) {
        if (condition) {
            throw assertion_failed("expected condition to be false, but it was not");
        }
    }
}