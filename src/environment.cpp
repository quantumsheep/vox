#include <vox/environment.hpp>

bool Vox::Environment::next_frame()
{
    if (this->window_should_close())
        return false;

    glfwPollEvents();

    return true;
}

void Vox::Environment::update_viewport() const
{
    int display_w = 0;
    int display_h = 0;

    glfwGetFramebufferSize(this->window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
}

void Vox::Environment::swap_buffers() const
{
    glfwSwapBuffers(this->window);
}
