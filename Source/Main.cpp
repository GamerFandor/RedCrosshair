/**
 * @file Main.cpp
 * @author Andor Fülöp <98351517+GamerFandor@users.noreply.github.com>
 * @brief The main file of the project
 * @version 1.0.0
 * @date 2023-12-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include "Core/Logger.hpp"
#include "Core/Application.hpp"
#include "Core/ConsoleAppManager.hpp"

int main(void)
{
    Application app;

    if (IsConsoleAppInstalled(ThirdPartyConsoleApp::nmap))
        Logger::Log("nmap is installed", LogLevel::Success);
    else
        Logger::Log("nmap is not installed", LogLevel::Error);
    if (IsConsoleAppInstalled(ThirdPartyConsoleApp::Metasploit))
        Logger::Log("Metasploit is installed", LogLevel::Success);
    else
        Logger::Log("Metasploit is not installed", LogLevel::Error);
        
    app.Run();

    return EXIT_SUCCESS;
}
