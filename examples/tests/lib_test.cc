#include <yatf/yatf.h>

#include "lib.h"

TEST_CASE(pass_test) {
    assert::pass();
}

TEST_CASE(fail_test) {
    assert::fail();
}

TEST_CASE(is_true_test) {
    assert::is_true(3 > 2);
}

TEST_CASE(is_false_test) {
    assert::is_false(2 > 3);
}

TEST_CASE(are_equal_test) {
    assert::are_equal(4, 4);
}

TEST_CASE(are_not_equal_test) {
    assert::are_not_equal(2, 3);
}

TEST_CASE(are_same_test) {
    const int val = 42;
    const int *ptr1 = &val;
    const int *ptr2 = &val;
    assert::are_same(val, val);
    assert::are_same(ptr1, ptr2);
}

TEST_CASE(are_not_same_test) {
    const int val1 = 42;
    const int val2 = 42;
    const int *ptr1 = &val1;
    const int *ptr2 = &val2;
    assert::are_not_same(val1, val2);
    assert::are_not_same(ptr1, ptr2);
}

TEST_CASE(is_zero_test) {
    assert::is_zero(0);
}

TEST_CASE(is_null_test) {
    int *ptr = nullptr;
    assert::is_null(ptr);
}

TEST_CASE(is_not_null_test) {
    int val = 5;
    int *ptr = &val;
    assert::is_not_null(ptr);
}

TEST_CASE(throws_test) {
    assert::throws([]() {
        throw std::exception();
    });
}

TEST_CASE(throws_type_test) {
    assert::throws<std::out_of_range>([]() {
        throw std::out_of_range("");
    });
}

TEST_CASE(does_not_throw_test) {
    assert::does_not_throw([](){});
}
