#include "assert.h"
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

    void throws(const std::function<void()> &function) {
        try {
            function();
        }
        catch (...) {
            throw assertion_passed();
        }
        throw assertion_failed("expected an exception to be thrown, but there was not");
    }

    void does_not_throw(const std::function<void()> &function) {
        try {
            function();
        }
        catch (...) {
            throw assertion_failed("expected no exception to be thrown, but there was");
        }
    }
}