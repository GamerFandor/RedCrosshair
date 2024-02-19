/**
 * @file Console.hpp
 * @author Andor Fülöp <98351517+GamerFandor@users.noreply.github.com>
 * @brief The Console class contains the console window and the logger functionallity
 * @version 1.0.0
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include <string>

class Console
{
public:
    /**
     * @brief Draw the console window to the screen
     * 
     * @param IsOpen Is the window currently open
     */
    void DrawWindow(bool* IsOpen);

private:
    /// @brief The filter string to search in the log messages
    std::string ConsoleFilter{""};
};
