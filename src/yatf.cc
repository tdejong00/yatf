#include "yatf.h"

#include <iostream>
#include <getopt.h>

void print_help() {
    std::cout << "YATF: Yet Another Testing Framework" << std::endl << std::endl;
    std::cout << "Usage: yatf [OPTIONS]... [FILE]..." << std::endl << std::endl;
    std::cout << "General options:" << std::endl;
    std::cout << "    -h --help           Display this help message." << std::endl;
    std::cout << "    -l --list           Lists the registered test files and cases." << std::endl << std::endl;
    std::cout << "Output options:" << std::endl;
    std::cout << "    -v --verbose        Enable verbose test reports." << std::endl;
    std::cout << "    -e --execution-time Enable execution times in the test reports." << std::endl;
    std::cout << "    -f --failed-only    Disable test reports for passed tests." << std::endl;
}

int main(int argc, char **argv) {
    /* Define command line options */
    const char *short_options = "hlvef";
    struct option long_options[] = { 
        { "help", no_argument, 0, 'h' },
        { "list", no_argument, 0, 'l' },
        { "verbose", no_argument, 0, 'v' },
        { "execution-time", no_argument, 0, 'e' },
        { "failed-only", no_argument, 0, 'f' },
        { 0, 0, 0, 0 }
    };
    int long_option_index = 0;
    
    bool show_help = false;
    bool show_list = false;
    yatf::report_options options = { false, false, true };

    /* Parse command line options */
    char option;
    while ((option = getopt_long(argc, argv, short_options, long_options, &long_option_index)) != -1) {
        switch (option) {
            case 'h': show_help = true; break;
            case 'l': show_list = true; break;
            case 'v': options.is_verbose = true; break;
            case 'e': options.show_execution_times = true; break;
            case 'f': options.show_passed_tests = false; break;
            default: exit(EXIT_FAILURE);
        }
    }

    yatf::test_runner runner(options);

    /* Show help display */
    if (show_help) {
        print_help();
    }
    /* List all registered test cases */
    else if (show_list) {
        runner.list_all_tests();
    }
    /* No test file(s) given, run all registered tests */
    else if (optind == argc) {
        runner.run_all_tests();
    }
    else {
        /* Run given test file(s) */
        while (optind < argc) {
            if (!runner.run_test_suite(argv[optind++])) {
                std::cerr << argv[0] << ": test suite '" << argv[optind - 1] << "' was not found" << std::endl;
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}
