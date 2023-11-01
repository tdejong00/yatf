#include <yatf/yatf.h>

#include "lib.h"

TEST_CASE(add_test) {
    assert::are_equal(add(5, 6), 11);
}

TEST_CASE(overflow_test) {
    assert::throws<std::overflow_error>([]() { 
        add(4, INT32_MAX - 2); 
    });
}

TEST_CASE(underflow_test) {
    assert::throws<std::underflow_error>([]() { 
        add(INT32_MIN + 4, -5);
    });
}
