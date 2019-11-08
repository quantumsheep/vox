#pragma once

#include <vox/color.hpp>
#include <vox/gl.hpp>

namespace Vox
{
class Camera
{
public:
    glm::vec3 position;
    glm::vec3 rotation;

    float aspect;

    float fov;
    float near;
    float far;

    Vox::Color background{0.45f, 0.55f, 0.60f, 1.00f};

    Camera(float width,
           float height,
           glm::vec3 position_ = glm::vec3(0.0f),
           glm::vec3 rotation_ = glm::vec3(0.0f),
           float fov_ = 60.0f,
           float near_ = 0.3f,
           float far_ = 1000.0f)
        : position(position_),
          rotation(rotation_),
          aspect(width / height),
          fov(fov_),
          near(near_),
          far(far_) {}

    glm::mat4 view() const;
    glm::mat4 projection() const;

    virtual void draw();
};
} // namespace Vox
