#pragma once

#include <vox/ui/bindings.hpp>

namespace Vox::UI
{
template <typename Function>
void Window(const char *name, ImGuiWindowFlags flags, Function body)
{
    Vox::UI::Begin(name, nullptr, flags);

    body();

    Vox::UI::End();
}

template <typename Function>
inline void Window(const char *name, Function body)
{
    return Vox::UI::Window(name, 0, body);
}
} // namespace Vox::UI
