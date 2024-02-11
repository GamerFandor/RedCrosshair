/**
 * @file Application.cpp
 * @author Andor Fülöp <98351517+GamerFandor@users.noreply.github.com>
 * @brief The implementation of the Application class
 * @version 1.0.0
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <cstdlib>
#include <Windows.h>
#include "Defines.hpp"
#include "Core/Application.hpp"

void Application::StartUp()
{
    // Implementation of Startup goes here
}

void Application::Update()
{  
    // Setting up ImGui Dockspaces
    static bool opt_fullscreen = true;
    static bool opt_padding = false;
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    ImGuiWindowFlags window_flags =  ImGuiWindowFlags_NoDocking;
    if (opt_fullscreen)
    {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }
    else
    {
        dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
    }

    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

    if (!opt_padding)
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace", nullptr, window_flags);
    if (!opt_padding)
        ImGui::PopStyleVar();

    if (opt_fullscreen)
        ImGui::PopStyleVar(2);

    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }

    // Setting up the menubar and other windows
    if (ImGui::BeginMainMenuBar()) 
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Quit", "Ctrl+Q")) exit(0);
            ImGui::EndMenu();
        } 

        if (ImGui::BeginMenu("Window")) 
        {
            if (ImGui::MenuItem("Console")) 
                ShowConsole = true;

            ImGui::EndMenu();
        }
        if (ImGui::MenuItem("About")) 
            ShowAbout = true;

        ImGui::EndMainMenuBar();
    }
    ImGui::End();

    if (ShowConsole) 
        Con.DrawWindow(&ShowConsole);
    if (ShowAbout) 
    {
        ImGui::SetNextWindowSize(ImVec2(500, 240));
        ImGui::Begin("About", &ShowAbout, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDocking);
        ImGui::SetCursorPosX(250 - ImGui::CalcTextSize("Red Crosshair").x * 0.5f);
        ImGui::Text("Red Crosshair");
        ImGui::SetCursorPosX(250 - ImGui::CalcTextSize("Version 0.0.0").x * 0.5f);
        ImGui::Text("Version %s", VERSION);
        ImGui::SetCursorPosX(200);
        if (ImGui::Button("Github", ImVec2(100, 23))) 
        {
            #ifdef PLATFORM_WINDOWS
                ShellExecuteA(NULL, "open", "https://github.com/GamerFandor/RedCrosshair", NULL, NULL, SW_SHOWNORMAL);
            #endif

            #ifdef PLATFORM_LINUX
                system("xdg-open https://github.com/GamerFandor/RedCrosshair")
            #endif

        }
        ImGui::SetCursorPosX(200);
        if (ImGui::Button("Manual", ImVec2(100, 23))) 
        {
            #ifdef PLATFORM_WINDOWS
                ShellExecuteA(NULL, "open", "https://github.com/GamerFandor/RedCrosshair/wiki/User-Manual#manual", NULL, NULL, SW_SHOWNORMAL);
            #endif

            #ifdef PLATFORM_LINUX
                system("xdg-open https://github.com/GamerFandor/RedCrosshair/wiki/User-Manual#manual")
            #endif

        }

        // End of the dockspace
        ImGui::End();
    }
}
