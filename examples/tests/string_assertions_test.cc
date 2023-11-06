#include <yatf/yatf.h>

TEST_CASE(is_empty_test) {
    assert::string::is_empty("");
}

TEST_CASE(is_not_empty_test) {
    assert::string::is_not_empty("test");
}

TEST_CASE(is_equal_test) {
    assert::string::is_equal("test", "test");
}

TEST_CASE(is_not_equal_test) {
    assert::string::is_not_equal("test1", "test2");
}

TEST_CASE(starts_with_test) {
    assert::string::starts_with("test", "te");
}

TEST_CASE(does_not_start_with_test) {
    assert::string::does_not_start_with("test", "st");
}

TEST_CASE(ends_with_test) {
    assert::string::ends_with("test", "st");
}

TEST_CASE(does_not_end_with_test) {
    assert::string::does_not_end_with("test", "te");
}

TEST_CASE(contains_test) {
    assert::string::contains("test", "es");
}

TEST_CASE(does_not_contain_test) {
    assert::string::does_not_contain("test", "se");
}

TEST_CASE(matches_test) {
    assert::string::matches("test", "[a-z]+");
}

TEST_CASE(does_not_match_test) {
    assert::string::does_not_match("test", "[A-Z]+");
}
