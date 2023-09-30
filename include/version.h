#ifndef __VERSION_H__
#define __VERSION_H__

#include <iostream>

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

#endif