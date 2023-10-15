#include <yatf/yatf.h>

#include "lib.h"

TEST_CASE(add_test) {
    int a = 5, b = 6;
    int expected = 11;

    int actual = add(a, b);

    yatf::assert::is_equal(actual, expected);
}
