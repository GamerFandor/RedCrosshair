/**
 * @file Console.cpp
 * @author Andor Fülöp <98351517+GamerFandor@users.noreply.github.com>
 * @brief The implementation of the Console class
 * @version 1.0.0
 * @date 2023-12-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "imgui.h"
#include <iostream>
#include "Windows.h"
#include "Defines.hpp"
#include "Core/Logger.hpp"
#include "UserInterface/Console.hpp"

/**
 * @brief Draw the console window to the screen
 * 
 * @param IsOpen Is the window currently open
 */
void Console::DrawWindow(bool* IsOpen)
{    
    ImGui::SetNextWindowSize(ImVec2(700, 200));
    if (ImGui::Begin("Console", IsOpen, ImGuiWindowFlags_NoCollapse))
    {
        ImGui::BeginChild("Child Window", ImVec2(ImGui::GetContentRegionAvail().x - 10, ImGui::GetContentRegionAvail().y - 27), true, ImGuiWindowFlags_AlwaysUseWindowPadding);
        auto LogMessages = Logger::GetLogMessages(ConsoleFilter);
        for (auto text : LogMessages)
        {
            ImGui::Text("%s", text.c_str());
        }
        if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) ImGui::SetScrollHereY(1.0f);
        ImGui::EndChild();

        if (ImGui::Button("Clear")) Logger::ClearLog();
        ImGui::SameLine();

        ImGui::Text("Filter:");
        ImGui::SameLine();
        char FilterBuffer[256];
        strncpy_s(FilterBuffer, ConsoleFilter.c_str(), sizeof(FilterBuffer));
        ImGui::InputText(" ", FilterBuffer, sizeof(FilterBuffer));
        ConsoleFilter = FilterBuffer;
        ImGui::End();
    }
}
