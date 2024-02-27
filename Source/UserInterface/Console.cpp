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
#include "Defines.hpp"
#ifdef PLATFORM_WINDOWS
    #include "Windows.h"
#endif
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
            if (text.find("[ + ]") != std::string::npos)
                ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "%s", text.c_str());
            else if (text.find("[ i ]") != std::string::npos)
                ImGui::TextColored(ImVec4(0.0f, 0.0f, 1.0f, 1.0f), "%s", text.c_str());
            else if (text.find("[ ! ]") != std::string::npos)
                ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "%s", text.c_str());
            else if (text.find("[ x ]") != std::string::npos)
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "%s", text.c_str());
            else
                ImGui::Text("%s", text.c_str());
        }
        if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) ImGui::SetScrollHereY(1.0f);
        ImGui::EndChild();

        if (ImGui::Button("Clear")) Logger::ClearLog();
        ImGui::SameLine();

        ImGui::Text("Filter:");
        ImGui::SameLine();
        char FilterBuffer[256];
        #ifdef PLATFORM_WINDOWS
            strncpy_s(FilterBuffer, ConsoleFilter.c_str(), sizeof(FilterBuffer));
        #else
            strncpy(FilterBuffer, ConsoleFilter.c_str(), sizeof(FilterBuffer));
        #endif
        ImGui::InputText(" ", FilterBuffer, sizeof(FilterBuffer));
        ConsoleFilter = FilterBuffer;
        ImGui::End();
    }
}
