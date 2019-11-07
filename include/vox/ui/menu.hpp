#pragma once

#include <iostream>
#include <vox/ui/bindings.hpp>
namespace Vox::UI
{
template <typename Function>
void MenuBar(Function body)
{
    if (Vox::UI::BeginMenuBar())
    {
        body();
        Vox::UI::EndMenuBar();
    }
}

template <typename Function>
void Menu(const char *name, Function body)
{
    if (Vox::UI::BeginMenu(name))
    {
        body();
        Vox::UI::EndMenu();
    }
}

template <typename Function>
void MenuItem(const char *name, const char *shortcut, Function execute)
{
    if (ImGui::MenuItem(name, shortcut))
        execute();
}

} // namespace Vox::UI
