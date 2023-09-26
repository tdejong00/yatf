#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <cstdarg>

/**
 * Provides logging functionality to log formatted result messages.
 */
class logger {
    public:        
        logger() = delete;
        ~logger() = delete;

        /**
         * Represents the result of an assertion.
         */
        enum result {
            unknown,
            failed,
            passed
        };

        /**
         * Logs a formatted info message.
         * 
         * @param format Specifies the structure of the log message.
         * @param ... Additional arguments to be formatted into the message.
         */
        static void info(const char *format, ...);

        /**
         * Logs a formatted fail message.
         * 
         * @param format Specifies the structure of the log message.
         * @param ... Additional arguments to be formatted into the message.
         */
        static void fail(const char *format, ...);

        /**
         * Logs a formatted pass message.
         * 
         * @param format Specifies the structure of the log message.
         * @param ... Additional arguments to be formatted into the message.
         */
        static void pass(const char *format, ...);
    
    private:
        static const constexpr char *RESET_COLOR = "\033[0;39m";
        static const constexpr char *GREEN_COLOR = "\033[32m";
        static const constexpr char *RED_COLOR = "\033[31m";

        /**
         * @brief Prints the result section of the log message.
         * 
         * @param result The result of the log message.
         */
        static void print_level(result result);

        /**
         * Logs a formatted message at the specified level.
         * 
         * @param result The result to log.
         * @param format Specifies the structure of the log message.
         * @param args Additional arguments to be formatted into the message.
         */
        static void log(result result, const char *format, va_list args);
};

#endif