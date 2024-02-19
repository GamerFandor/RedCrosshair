/**
 * @file Logger.hpp
 * @author Andor Fülöp <98351517+GamerFandor@users.noreply.github.com>
 * @brief Logger class that stores and handles log messages
 * @version 1.0.0
 * @date 2024-02-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <string>
#include <vector>

/**
 * @brief Level of importance of the log messages
 * 
 */
enum class LogLevel
{
    Success = 0,
    Info = 1,
    Warning = 2,
    Error = 3
};

/**
 * @brief Class to store and handle log messages
 * 
 */
class Logger
{
public: 
    /**
     * @brief Add a log message to the log message vector
     * 
     * @param Message The log message
     * @param Level The importance level of the log message
     */   
    static void Log(const std::string& Message, LogLevel Level = LogLevel::Info);

    /**
     * @brief Get the Log Messages and filter them if needed
     * 
     * @param Filter The text to look for in the messages to filter the log message pool
     * @return The filtered log messages
     */
    static std::vector<std::string> GetLogMessages(std::string Filter = "");

    /**
     * @brief Clears the log message vector
     * 
     */
    static void ClearLog();

    /// @brief The vector that stores the log messages 
    static std::vector<std::string> LogMessages;
};