/**
 * @file ConsoleAppManager.hpp
 * @author Andor Fülöp <98351517+GamerFandor@users.noreply.github.com>
 * @brief Check whether a console application is installed and executes console commands
 * @version 1.0.0
 * @date 2024-02-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <string>

/**
 * @brief Third party console applications that is required for the program to work (using enum instead of string to avoid typos)
 * 
 */
enum class ThirdPartyConsoleApp
{
    nmap,
    Metasploit,
    PowershellEmpire
    // The list goes on but it's enough for now
};

/**
 * @brief Checks whether a console application is installed
 * 
 * @param App The console application to check
 * @return Gives true if the console application is installed otherwise gives false
 */
bool IsConsoleAppInstalled(ThirdPartyConsoleApp App);

/**
 * @brief Executes a console command
 * 
 * @param Command The command to execute
 * @return The output of the command
 */
std::string ExecuteConsoleCommand(std::string Command);
