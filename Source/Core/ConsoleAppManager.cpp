/**
 * @file ConsoleAppManager.cpp
 * @author Andor Fülöp <98351517+GamerFandor@users.noreply.github.com>
 * @brief Implementation of ConsoleAppManager.hpp
 * @version 1.0.0
 * @date 2024-02-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "Defines.hpp"
#ifdef PLATFORM_WINDOWS
    #include <Windows.h>
#else 
    #include <stdio.h>
#endif
#include "Core/Logger.hpp"
#include "Core/ConsoleAppManager.hpp"

/**
 * @brief Checks whether a console application is installed
 * 
 * @param App The console application to check
 * @return Gives true if the console application is installed otherwise gives false
 */
bool IsConsoleAppInstalled(ThirdPartyConsoleApp App)
{
    // Get the App's actual console command
    std::string ApplicationName;
    switch (App)
    {
    case ThirdPartyConsoleApp::nmap:
        ApplicationName = "nmap";
        break;
    case ThirdPartyConsoleApp::Metasploit:
        ApplicationName = "msfconsole";
        break;
    case ThirdPartyConsoleApp::PowershellEmpire:
        ApplicationName = "powershell-empire";
        break;
    }

    // Check if the console application is installed
    #ifdef PLATFORM_WINDOWS
        //std::string result = ExecuteConsoleCommand("Get-Command -Name " + ApplicationName);
        std::string result = ExecuteConsoleCommand("Get-Command -Name calc");
    #elif PLATFORM_LINUX
        std::string result = ExecuteConsoleCommand("which " + ApplicationName);
    #endif

    if (result != "")
        return true;
    return false;
}


// NOTE: Doesn't work on Windows properly, Linux is not tested

/**
 * @brief Executes a console command
 * 
 * @param Command The command to execute
 * @return The output of the command
 */
std::string ExecuteConsoleCommand(std::string Command)
{
    // Convert the command to the actual console command
    #ifdef PLATFORM_WINDOWS
        std::string ConcatCommand = "powershell -Command " + Command;
        const char* CMD = ConcatCommand.c_str();
        std::string CmdStr(CMD);

        // Create process information structure
        PROCESS_INFORMATION processInfo;
        ZeroMemory(&processInfo, sizeof(processInfo));

        // Create startup info structure
        STARTUPINFO startupInfo;
        ZeroMemory(&startupInfo, sizeof(startupInfo));
        startupInfo.cb = sizeof(startupInfo);

        if (CreateProcess(
            NULL,               
            (LPSTR)CMD,      
            NULL,             
            NULL,               
            FALSE,          
            0,                
            NULL,           
            NULL,           
            &startupInfo,   
            &processInfo 
        )) 
        {
            // Wait for the process to finish
            WaitForSingleObject(processInfo.hProcess, INFINITE);

            // Close process and thread handles
            CloseHandle(processInfo.hProcess);
            CloseHandle(processInfo.hThread);

            return "Test Value";
        } 
        else 
        {
            Logger::Log("Error creating process while executeing console command (" + CmdStr + ")", LogLevel::Error);
        }

    #elif PLATFORM_LINUX
        const char* CMD = Command.c_str();
        std::string CmdStr(CMD);

        // Open a pipe to the command
        FILE* pipe = popen(CMD, "r");
        if (!pipe) 
        {
            Logger::Log("Error opening pipe to execute a console command. (" + CmdStr + ")", LogLevel::Error);
            return "";
        }

        // Read the console output
        char buffer[128];
        std::string result = "";
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
            result += buffer;

        // Close the pipe
        int status = pclose(pipe);

        // Check the return value
        if (status == 0)
            return result;
        else
            Logger::Log("Command (" + CmdStr + ") failed with status " + std::to_string(status), LogLevel::Error);
    #endif

    return "";
}