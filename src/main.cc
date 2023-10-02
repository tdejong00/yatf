#include <cstring>
#include <getopt.h>

#include "test_registry.h"
#include "test_runner.h"
#include "test_reporter.h"

/**
 * @brief Gets the major version number defined in the Makefile.
 * 
 * @return The major version number.
 */
int get_major_version() {
    #ifdef MAJOR
        return MAJOR;
    #else
        printf("MAJOR was not defined in the Makefile\n");
        exit(EXIT_FAILURE);
    #endif
}

/**
 * @brief Gets the minor version number defined in the Makefile.
 * 
 * @return The minor version number.
 */
int get_minor_version() {
    #ifdef MINOR
        return MINOR;
    #else
        printf("MINOR was not defined in the Makefile\n");
        exit(EXIT_FAILURE);
    #endif
}

/**
 * @brief Gets the patch version number defined in the Makefile.
 * 
 * @return The patch version number.
 */
int get_patch_version() {
    #ifdef PATCH
        return PATCH;
    #else
        printf("PATCH was not defined in the Makefile\n");
        exit(EXIT_FAILURE);
    #endif
}

/**
 * @brief Prints the program name and version.
 */
void print_version() {
    printf("YATF: Yet Another Testing Framework v%d.%d.%d\n\n", get_major_version(), get_minor_version(), get_patch_version());
}

/**
 * @brief Prints the help display.
 */
void print_help() {
    print_version();
    printf("Usage: yatf [OPTIONS]... [FILE]...\n\n");
    printf("General options:\n");
    printf("    -h --help           Display this help message.\n");
    printf("    -v --version        Display the version string.\n");
    printf("    -l --list           Lists the registered test files and cases.\n\n");
    printf("Output options:\n");
    printf("    -V --verbose        Enable verbose test reports.\n");
    printf("    -E --execution-time Enable execution times in the test reports.\n");
    printf("    -F --failed-only    Disable test reports for passed tests.\n");
}

int main(int argc, char **argv) {
    /* Define command line options */
    const char *short_options = "hvlVEF";
    struct option long_options[] = { 
        { "help", no_argument, 0, 'h' }, 
        { "version", no_argument, 0, 'v' },
        { "list", no_argument, 0, 'l' },
        { "verbose", no_argument, 0, 'V' },
        { "execution-time", no_argument, 0, 'E' },
        { "failed-only", no_argument, 0, 'F' },
        { 0, 0, 0, 0 }
    };
    int long_option_index = 0;
    
    test_framework::report_options options = { false, false, true };
    bool show_list = false;

    /* Parse command line options */
    char option;
    while ((option = getopt_long(argc, argv, short_options, long_options, &long_option_index)) != -1) {
        switch (option) {
            case 'h': print_help(); exit(EXIT_SUCCESS);
            case 'v': print_version(); exit(EXIT_SUCCESS);
            case 'l': show_list = true; break;
            case 'V': options.is_verbose = true; break;
            case 'E': options.show_execution_times = true; break;
            case 'F': options.show_passed_tests = false; break;
            default: exit(EXIT_FAILURE);
        }
    }

    test_framework::test_reporter reporter(options);
    test_framework::test_runner runner(reporter);

    /* List all registered test cases. */
    if (show_list) {
        runner.list_all_tests();
    }
    /* No test file(s) given, run all registered tests */
    else if (optind == argc) {
        runner.run_all_tests();
    }
    else {
        /* Run given test file(s) */
        while (optind < argc) {
            runner.run_test_suite(argv[optind++]);
        }
    }

    return EXIT_SUCCESS;
}
