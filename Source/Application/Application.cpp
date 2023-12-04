#include <cstdlib>
#include "Application/Application.hpp"

void Application::StartUp()
{
    // Implementation of Startup goes here
}

void Application::Update()
{
    if (ImGui::BeginMainMenuBar()) 
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Quit", "Ctrl+Q")) 
                exit(0);
            ImGui::EndMenu();
        } 

        ImGui::EndMainMenuBar();
    }
}
