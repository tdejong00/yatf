#include <yatf/yatf.h>

TEST_CASE(is_zero_test) {
    assert::is_zero(0);
}

TEST_CASE(is_not_zero_test) {
    assert::is_not_zero(1);
}

TEST_CASE(is_positive_test) {
    assert::is_positive(1);
}

TEST_CASE(is_negative_test) {
    assert::is_negative(-1);
}

TEST_CASE(is_greater_than_test) {
    assert::is_greater_than(2, 1);
}

TEST_CASE(is_greater_or_equal_than_test) {
    assert::is_greater_or_equal_than(1, 1);
    assert::is_greater_or_equal_than(2, 1);
}

TEST_CASE(is_less_than_test) {
    assert::is_less_than(1, 2);
}

TEST_CASE(is_less_or_equal_than_test) {
    assert::is_less_or_equal_than(1, 1);
    assert::is_less_or_equal_than(1, 2);
}
