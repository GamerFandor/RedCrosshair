/**
 * @file Defines.hpp
 * @author Andor Fülöp <98351517+GamerFandor@users.noreply.github.com>
 * @brief This files contains some definitions that used throughout the program.
 * @version 1.0.0
 * @date 2023-12-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

/// @brief The version number of the application
#define VERSION "1.0.0"

/**
 * @brief Determineing which platform is being used
 * 
 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define PLATFORM_WINDOWS 1
#elif __linux__
    #define PLATFORM_LINUX 1
#else
    #error "Unknown compiler"
#endif
