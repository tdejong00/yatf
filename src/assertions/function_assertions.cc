#include "assertions/function_assertions.h"

namespace assert {
    namespace function {
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
}