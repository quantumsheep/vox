#pragma once

#include <memory>
#include <vox/bindings.hpp>
#include <vox/environment.hpp>

namespace Vox::Cursor
{
glm::vec2 GetPosition(std::unique_ptr<Vox::Environment> &env);

void SetMode(std::unique_ptr<Vox::Environment> &env, Vox::CursorMode mode);
void Stuck(std::unique_ptr<Vox::Environment> &env);

inline void Show(std::unique_ptr<Vox::Environment> &env)
{
    return SetMode(env, Vox::CursorMode::Normal);
}

inline void Free(std::unique_ptr<Vox::Environment> &env)
{
    return Show(env);
}

inline void Hide(std::unique_ptr<Vox::Environment> &env)
{
    return SetMode(env, Vox::CursorMode::Hidden);
}

inline void Disable(std::unique_ptr<Vox::Environment> &env)
{
    return SetMode(env, Vox::CursorMode::Normal);
}
} // namespace Vox::Cursor
