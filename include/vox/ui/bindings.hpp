#pragma once

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Vox::UI
{
using namespace ImGui;

typedef ImGuiIO IO;

inline void NewFrame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

inline void Draw()
{
    ImGui_ImplOpenGL3_RenderDrawData(Vox::UI::GetDrawData());
}
} // namespace Vox::UI
