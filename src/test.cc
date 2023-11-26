#include <iostream>
#include <iomanip>

#include "test.h"

namespace yatf {
    /**
     * The floating point precision of milliseconds.
     */
    const int MILLISECONDS_PRECISION = 6;
    
    /**
     * Seconds to milliseconds ratio.
     */
    const int MILLISECONDS_RATIO = 1000;

    std::ostream &operator<<(std::ostream &stream, const test_case &test_case) {
        return stream << test_case.file_name << ":" << test_case.name;
    }

    std::ostream &operator<<(std::ostream &stream, const test_suite &test_suite) {
        return stream << test_suite.name << ":";
    }

    std::ostream &operator<<(std::ostream &stream, const test_result &test_result) {
        switch (test_result) {
            case test_result::FAILED: return stream << color::RED << "FAIL: " << color::RESET;
            case test_result::PASSED: return stream << color::GREEN << "OK:   " << color::RESET;
            default: return stream << color::ORANGE;
        }
    }

    std::ostream &operator<<(std::ostream &stream, const color &color) {
        switch (color) {
            case color::RED: return stream << "\033[31m";
            case color::GREEN: return stream << "\033[32m";
            case color::ORANGE: return stream << "\033[33m";
            case color::GRAY: return stream << "\033[90m";
            default: return stream << "\033[0;39m";
        }
    }

    test_statistics operator-(const test_statistics &first, const test_statistics &second) {
        return {
            first.total_count - second.total_count, 
            first.passed_count - second.passed_count, 
            first.failed_count - second.failed_count
        };
    }

    std::ostream &operator<<(std::ostream &stream, const test_statistics &test_statistics) {
        return stream << (test_statistics.failed_count > 0 ? color::RED : color::GREEN)
            << test_statistics.passed_count << (test_statistics.passed_count == 1 ? " test " : " tests ") 
            << "passed, " << test_statistics.failed_count << (test_statistics.failed_count == 1 ? " test " : " tests ") 
            << "failed" << color::RESET;
    }

    std::ostream &operator<<(std::ostream &stream, const std::chrono::duration<double> &duration) {
        return stream << "(" << std::fixed << std::setprecision(MILLISECONDS_PRECISION)
            << duration.count() * MILLISECONDS_RATIO << " ms)";
    }
}