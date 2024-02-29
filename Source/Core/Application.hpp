/**
 * @file Application.hpp
 * @author Andor Fülöp <98351517+GamerFandor@users.noreply.github.com>
 * @brief Contains the Application class that contains the main loop of the program
 * @version 1.0.0
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once

#include "Core/ImGuiFramework.hpp"
#include "UserInterface/Console.hpp"

/**
 * @brief The main class of the program
 * 
 */
class Application : public ImGuiFramework
{
public:
    /**
     * @brief Construct a new Application object to pass basic info
     * 
     */
    Application() = default;

    /**
     * @brief Cleanup when the app is closed
     * 
     */
    ~Application() = default;

    /**
     * @brief Configure the application (mainly ImGui)
     * 
     */
    virtual void StartUp() final;

    /**
     * @brief The main loop of the program
     * 
     */
    virtual void Update() final;

private:
    /// @brief Console window visibility
    bool ShowConsole = true;

    /// @brief About window visibility
    bool ShowAbout = false;

    /// @brief Console object
    Console Con;
};
