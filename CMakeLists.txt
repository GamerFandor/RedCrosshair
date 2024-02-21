cmake_minimum_required(VERSION 3.27)

project(RedCrosshair)

add_subdirectory(Vendor/GLFW)

file(GLOB_RECURSE SOURCE "Source/*.cpp" "Source/**/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} PRIVATE glfw opengl32)

target_sources(${PROJECT_NAME} PRIVATE
    Vendor/ImGui/imgui_draw.cpp
    Vendor/ImGui/imgui_tables.cpp
    Vendor/ImGui/imgui_widgets.cpp
    Vendor/ImGui/imgui.cpp
    Vendor/ImGui/backends/imgui_impl_glfw.cpp
    Vendor/ImGui/backends/imgui_impl_opengl3.cpp

    Vendor/PugiXML/src/pugixml.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
    Source/
    Source/**/

    Vendor/GLFW/include

    Vendor/ImGui
    Vendor/ImGui/backends

    Vendor/PugiXML/src
)
