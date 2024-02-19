/**
 * @file Logger.cpp
 * @author Andor Fülöp <98351517+GamerFandor@users.noreply.github.com>
 * @brief Implementation of the Logger class
 * @version 1.0.0
 * @date 2024-02-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <ctime>
#include <chrono>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Defines.hpp"
#include "Core/Logger.hpp"

/// @brief The vector that stores the log messages 
std::vector<std::string> Logger::LogMessages;

/**
 * @brief Add a log message to the log message vector
 * 
 * @param Message The log message
 * @param Level The importance level of the log message
 */
void Logger::Log(const std::string& Message, LogLevel Level)
{
    size_t LevelIndex = static_cast<size_t>(Level);
    std::string LevelStrings[4] = {"[ + ]", "[ i ]", "[ ! ]", "[ x ]"};
    
    // Get current time in "HH:MM:SS" format
    auto Now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm TimeInfo;
    #ifdef PLATFORM_WINDOWS
        localtime_s(&TimeInfo, &Now); // Use secure version on Windows
    #else
        localtime_r(&Now, &TimeInfo); // Use the POSIX version on other systems
    #endif
    std::stringstream TimeStringStream;
    TimeStringStream << std::put_time(&TimeInfo, "%T");
    std::string TimeString = TimeStringStream.str();

    std::string FinalLog = LevelStrings[LevelIndex] + " [" + TimeString + "] " +Message;
    Logger::LogMessages.push_back(FinalLog);
}

/**
 * @brief Get the Log Messages and filter them if needed
 * 
 * @param Filter The text to look for in the messages to filter the log message pool
 * @return The filtered log messages
 */
std::vector<std::string> Logger::GetLogMessages(std::string Filter)
{
    std::vector<std::string> FilteredMessages;

    for (auto Msg : Logger::LogMessages)
    {
        std::string MsgLowercase = Msg;
        std::transform(MsgLowercase.begin(), MsgLowercase.end(), MsgLowercase.begin(), [](unsigned char c){ return std::tolower(c); });
        std::transform(Filter.begin(), Filter.end(), Filter.begin(), [](unsigned char c){ return std::tolower(c); });
        if (Filter != "" && MsgLowercase.find(Filter) == std::string::npos) continue;
        FilteredMessages.push_back(Msg);
    }

    return FilteredMessages;
}

/**
 * @brief Clears the log message vector
 * 
 */
void Logger::ClearLog()
{
    Logger::LogMessages.clear();
}