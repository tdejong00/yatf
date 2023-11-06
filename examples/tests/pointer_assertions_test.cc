#include <yatf/yatf.h>

TEST_CASE(is_null_test) {
    int *ptr = nullptr;
    assert::pointer::is_null(ptr);
}

TEST_CASE(is_not_null_test) {
    int val = 5;
    int *ptr = &val;
    assert::pointer::is_not_null(ptr);
}

TEST_CASE(isblank_l) {
    const int val = 1;
    const int *ptr1 = &val;
    const int *ptr2 = &val;
    assert::pointer::is_same(ptr1, ptr2);
}

TEST_CASE(is_not_same_test) {
    const int val1 = 1;
    const int val2 = 1;
    const int *ptr1 = &val1;
    const int *ptr2 = &val2;
    assert::pointer::is_not_same(ptr1, ptr2);
}
