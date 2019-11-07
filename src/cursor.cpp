#include <vox/cursor.hpp>

glm::vec2 Vox::Cursor::GetPosition(std::unique_ptr<Vox::Environment> &env)
{
    glm::vec<2, double> pos;
    glfwGetCursorPos(env->window, &pos.x, &pos.y);

    return pos;
}