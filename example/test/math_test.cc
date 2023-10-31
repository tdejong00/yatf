#include <yatf/yatf.h>

#include "lib.h"

TEST_CASE(add_test) {
    const int expected = 11;

    const int actual = add(5, 6);

    yatf::assert::is_equal(actual, expected);
}
