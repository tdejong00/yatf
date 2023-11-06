#include <yatf/yatf.h>

TEST_CASE(is_empty_test) {
    std::vector<int> v = { };
    assert::collection::is_empty(v);
}

TEST_CASE(is_not_empty_test) {
    std::vector<int> v = { 1, 2, 3 };
    assert::collection::is_not_empty(v);
}

TEST_CASE(contains_test) {
    std::vector<int> v = { 1, 2 , 3 };
    assert::collection::contains(v, 2);
}

TEST_CASE(does_not_contain_test) {
    std::vector<int> v = { 1, 2 , 3 };
    assert::collection::does_not_contain(v, 4);
}

TEST_CASE(is_equal_test) {
    std::vector<int> v1 = { 1, 2, 3 };
    std::vector<int> v2 = { 1, 2, 3 };
    assert::collection::is_equal(v1, v2);
}

TEST_CASE(is_not_equal_test) {
    std::vector<int> v1 = { 1, 2, 3 };
    std::vector<int> v2 = { 1, 2, 4 };
    assert::collection::is_not_equal(v1, v2);
}

TEST_CASE(is_not_equal_different_size_test) {
    std::vector<int> v1 = { 1, 2, 3 };
    std::vector<int> v2 = { 1, 2, 3, 4 };
    assert::collection::is_not_equal(v1, v2);
}
