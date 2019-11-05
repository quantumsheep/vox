#pragma once

#include <vox/ui/bindings.hpp>

namespace Vox::UI
{
class Window
{
public:
    template <typename Function>
    static void Create(const char *name, Function body)
    {
        ImGui::Begin(name);

        body();

        ImGui::End();
    }
};
} // namespace Vox::UI
