#pragma once

#include "Application/ImGuiFramework.hpp"

class Application : public ImGuiFramework
{
public:
    Application() = default;
    ~Application() = default;
    virtual void StartUp() final;
    virtual void Update() final;

private:
};
