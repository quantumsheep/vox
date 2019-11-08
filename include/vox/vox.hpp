#pragma once

#include <vox/bindings.hpp>
#include <vox/gl.hpp>

#include <vox/environment.hpp>

#include <vox/ui/bindings.hpp>

#include <vox/ui/menu.hpp>
#include <vox/ui/window.hpp>

#include <vox/camera.hpp>
#include <vox/color.hpp>
#include <vox/cursor.hpp>
#include <vox/keyboard.hpp>
#include <vox/log.hpp>
#include <vox/object.hpp>
#include <vox/shader.hpp>
#include <vox/vertex.hpp>

#include <cstdio>
#include <memory>

namespace Vox
{
std::unique_ptr<Vox::Environment> Init(int width, int height, const char *title, bool debug = false, std::size_t antialiasing = 4, Vox::Monitor *monitor = nullptr, Vox::Window *share = nullptr);
} // namespace Vox
