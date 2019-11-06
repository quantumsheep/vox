#include <vox/environment.hpp>

bool Vox::Environment::next_frame()
{
    if (this->window_should_close())
        return false;

    glfwPollEvents();

    return true;
}

void Vox::Environment::update_viewport()
{
    glfwGetFramebufferSize(this->window, &this->width, &this->height);
    glViewport(0, 0, this->width, this->height);
}

void Vox::Environment::swap_buffers() const
{
    glfwSwapBuffers(this->window);
}
