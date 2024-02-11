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

// TODO: Separate the logger and the console window into two different classes
#pragma once

#include <vector>
#include <string>

class Console
{
public:
    void DrawWindow(bool* IsOpen);
    static void Log(const std::string& Message);
    void ClearConsole();

private:
    static std::vector<std::string> ConsoleOutputBuffer;
    std::string ConsoleFilter{""};
};
