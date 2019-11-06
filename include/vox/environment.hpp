#pragma once

#include <vox/bindings.hpp>
#include <vox/ui/bindings.hpp>

namespace Vox
{
class Environment
{
public:
    Vox::Window *window = nullptr;
    Vox::UI::IO &ui_io;

    int width = 0;
    int height = 0;

    ~Environment()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(window);
        glfwTerminate();
    }

    Environment(Vox::Window *window_, Vox::UI::IO &ui_io_) : window(window_), ui_io(ui_io_)
    {
        this->update_viewport();
    }

    inline bool window_should_close() const
    {
        return (bool)glfwWindowShouldClose(this->window);
    }

    bool next_frame();
    void update_viewport();
    void swap_buffers() const;
};
} // namespace Vox
