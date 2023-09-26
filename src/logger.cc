#include <iostream>
#include <ctime>

#include "logger.h"

void logger::info(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log(result::unknown, format, args);
    va_end(args);
}

void logger::fail(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log(result::failed, format, args);
    va_end(args);
}

void logger::pass(const char *format, ...) {
    va_list args;
    va_start(args, format);
    log(result::passed, format, args);
    va_end(args);
}

void logger::print_level(result level) {
    switch (level) {
        case logger::result::failed:
            printf("%s[FAILED]%s: ", RED_COLOR, RESET_COLOR);
            break;
        case logger::result::passed:
            printf("%s[PASSED]%s: ", GREEN_COLOR, RESET_COLOR);
            break;
        default: printf("[INFO]: ");
            break;
    }
}

void logger::log(result level, const char *format, va_list args) {
    print_level(level);
    vprintf(format, args);
    printf("\n");
}
