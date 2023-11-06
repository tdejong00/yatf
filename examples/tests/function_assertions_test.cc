#include <yatf/yatf.h>

TEST_CASE(throws_test) {
    assert::function::throws([]() {
        throw std::exception();
    });
}

TEST_CASE(throws_type_test) {
    assert::function::throws<std::out_of_range>([]() {
        throw std::out_of_range("");
    });
}

TEST_CASE(does_not_throw_test) {
    assert::function::does_not_throw([](){});
}
