#pragma once

#include <vox/bindings.hpp>
#include <vox/environment.hpp>

namespace Vox::Keyboard
{
inline bool KeyUp(std::unique_ptr<Vox::Environment> &env, Vox::KeyboardKey key)
{
    return glfwGetKey(env->window, static_cast<int>(key)) == GLFW_RELEASE;
}

inline bool KeyDown(std::unique_ptr<Vox::Environment> &env, Vox::KeyboardKey key)
{
    return glfwGetKey(env->window, static_cast<int>(key)) == GLFW_PRESS;
}

inline bool KeyHold(std::unique_ptr<Vox::Environment> &env, Vox::KeyboardKey key)
{
    return glfwGetKey(env->window, static_cast<int>(key)) == GLFW_REPEAT;
}

inline bool KeyDownOrHold(std::unique_ptr<Vox::Environment> &env, Vox::KeyboardKey key)
{
    int mode = glfwGetKey(env->window, static_cast<int>(key));
    return mode == GLFW_PRESS || mode == GLFW_REPEAT;
}
} // namespace Vox::Keyboard
