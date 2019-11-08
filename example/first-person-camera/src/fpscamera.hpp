#include <vox/vox.hpp>

class FPSCamera : public Vox::Camera
{
public:
    using Vox::Camera::Camera;

    void update(std::unique_ptr<Vox::Environment> &env);
};
