#pragma once

namespace Vox
{
struct Color
{
    float r;
    float g;
    float b;
    float a;

    static float *to_floats(Color *color)
    {
        return reinterpret_cast<float *>(color);
    }
};
} // namespace Vox
