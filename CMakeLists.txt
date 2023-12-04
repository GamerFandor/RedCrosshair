cmake_minimum_required(VERSION 3.27)

project(CrimsonSoldier)

add_subdirectory(Vendor/GLFW)

file(GLOB_RECURSE SOURCE "Source/*.cpp" "Source/**/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

target_sources(${PROJECT_NAME} PRIVATE 
    Vendor/ImGui/imgui_draw.cpp
    Vendor/ImGui/imgui_tables.cpp
    Vendor/ImGui/imgui_widgets.cpp
    Vendor/ImGui/imgui.cpp
    "Vendor/ImGui/backends/imgui_impl_glfw.cpp"
)

target_include_directories(${PROJECT_NAME} PRIVATE
    Source/
    Source/**/
    Vendor/ImGui
    Vendor/GLFW/include
)
