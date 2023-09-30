#include "test_runner.h"
#include "version.h"

#include <getopt.h>

void print_version() {
    printf("YATF: Yet Another Testing Framework v%d.%d.%d\n", get_major_version(), get_minor_version(), get_patch_version());
}

void print_help() {
    print_version();
    printf("Free and open source software under the terms of the MIT license.\n\n");
    printf("Usage: yatf [OPTIONS]... [FILE]...\n\n");
    printf("General options:\n");
    printf("    -h --help               Display this help message.\n");
    printf("    -v --version            Display the version string.\n");
    printf("    -l --list               Lists the registered test suites and cases.\n");
    printf("    -f --file <file_name>   Runs a specific test suite.\n");
    printf("    -t --test <test_name>   Runs a specific test case.\n\n");
    printf("Output options:\n");
    printf("    TODO                    \n");
}

int main(int argc, char **argv) {
    /* Define command line options */
    const char *short_options = "hvlf:t:";
    struct option long_options[] = { 
        { "help", no_argument, 0, 'h' }, 
        { "version", no_argument, 0, 'v' },
        { "list", no_argument, 0, 'l' },
        { "file", required_argument, 0, 'f' },
        { "test", required_argument, 0, 't' },
        { 0, 0, 0, 0 } /* to prevent segfaults */
    };
    int long_option_index = 0;

    const char *test_suite_name = nullptr;
    const char *test_case_name = nullptr;

    /* Parse command line options */
    char option;
    while ((option = getopt_long(argc, argv, short_options, long_options, &long_option_index)) != -1) {
        switch (option) {
            case 'h':
                print_help();
                exit(EXIT_SUCCESS);
            case 'v':
                print_version();
                exit(EXIT_SUCCESS);
            case 'l':
                test_framework::test_runner::list_all_tests();
                exit(EXIT_SUCCESS);
            case 'f':
                test_suite_name = optarg;
                break;
            case 't':
                test_case_name = optarg;
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }

    /* Run specific test suite */
    if (test_suite_name != nullptr && test_case_name == nullptr) {
        if (!test_framework::test_runner::run_test_suite(test_suite_name)) {
            fprintf(stderr, "%s: test suite %s does not exist\n", argv[0], test_suite_name);
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    /* Run specific test case */
    else if (test_suite_name != nullptr && test_case_name != nullptr) {
        if (!test_framework::test_runner::run_test_case(test_suite_name, test_case_name)) {
            fprintf(stderr, "%s: test case %s in test suite %s does not exist\n", argv[0], test_case_name, test_suite_name);
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
    /* No test suite name given */
    else if (test_suite_name == nullptr && test_case_name != nullptr) {
        fprintf(stderr, "%s: no test suite given for test case %s\n", argv[0], test_case_name);
        exit(EXIT_FAILURE);
    }
    /* Run all tests */
    else {
        test_framework::test_runner::run_all_tests();
    }

    return EXIT_SUCCESS;
}
