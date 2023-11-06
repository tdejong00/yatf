#include <yatf/yatf.h>

TEST_CASE(pass_test) {
    assert::pass();
}

TEST_CASE(fail_test) {
    assert::fail();
}

TEST_CASE(message_test) {
    assert::message("this is a message");
}

TEST_CASE(is_true_test) {
    assert::is_true(2 > 1);
}

TEST_CASE(is_false_test) {
    assert::is_false(1 > 2);
}

TEST_CASE(is_equal_test) {
    assert::is_equal(1, 1);
}

TEST_CASE(is_not_equal_test) {
    assert::is_not_equal(1, 2);
}

TEST_CASE(are_same_test) {
    const int val = 1;
    assert::is_same(val, val);
}

TEST_CASE(are_not_same_test) {
    const int val1 = 1;
    const int val2 = 1;
    assert::is_not_same(val1, val2);
}
