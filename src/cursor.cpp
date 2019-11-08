#include <vox/cursor.hpp>

glm::vec2 Vox::Cursor::GetPosition(std::unique_ptr<Vox::Environment> &env)
{
    glm::vec<2, double> pos;
    glfwGetCursorPos(env->window, &pos.x, &pos.y);

    return pos;
}

void Vox::Cursor::SetMode(std::unique_ptr<Vox::Environment> &env, Vox::CursorMode mode)
{
    glfwSetInputMode(env->window, GLFW_CURSOR, static_cast<int>(mode));
}

void Vox::Cursor::Stuck(std::unique_ptr<Vox::Environment> &env)
{
    SetMode(env, Vox::CursorMode::Disabled);
    glfwSetCursorPos(env->window, 0, 0);
}
