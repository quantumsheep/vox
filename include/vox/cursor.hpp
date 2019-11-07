#pragma once

#include <memory>
#include <vox/environment.hpp>

namespace Vox::Cursor
{
glm::vec2 GetPosition(std::unique_ptr<Vox::Environment> &env);
} // namespace Vox::Cursor
