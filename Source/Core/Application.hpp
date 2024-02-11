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

class Application : public ImGuiFramework
{
public:
    Application() = default;
    ~Application() = default;
    virtual void StartUp() final;
    virtual void Update() final;

private:
    bool ShowConsole = true;
    bool ShowAbout = false;

    Console Con;
};
