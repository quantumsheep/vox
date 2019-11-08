#include "fpscamera.hpp"

void FPSCamera::update(std::unique_ptr<Vox::Environment> &env)
{
    static bool in = false;

    if (Vox::Keyboard::KeyDown(env, Vox::KeyboardKey::P))
    {
        if (in)
            Vox::Cursor::Free(env);
        else
            Vox::Cursor::Stuck(env);

        in = !in;
    }

    if (!in)
    {
        return;
    }

    glm::vec2 cursor = Vox::Cursor::GetPosition(env);
    static glm::vec2 last_position = cursor;

    float sensitivity = 0.1f;
    this->rotation.x += (cursor.x - last_position.x) * sensitivity;
    this->rotation.y += (cursor.y - last_position.y) * sensitivity;

    last_position = cursor;

    static float last_frame = 0.0f;

    float current_frame = glfwGetTime();
    float delta_time = current_frame - last_frame;
    last_frame = current_frame;

    float speed = 0.12f;

    float move = speed * delta_time;

    float dx = 0;
    float dy = 0;
    float dz = 0;

    if (Vox::Keyboard::KeyDownOrHold(env, Vox::KeyboardKey::W))
        dz += 2;

    if (Vox::Keyboard::KeyDownOrHold(env, Vox::KeyboardKey::S))
        dz -= 2;

    if (Vox::Keyboard::KeyDownOrHold(env, Vox::KeyboardKey::D))
        dx += 2;

    if (Vox::Keyboard::KeyDownOrHold(env, Vox::KeyboardKey::A))
        dx -= 2;

    if (Vox::Keyboard::KeyDownOrHold(env, Vox::KeyboardKey::Space))
        dy += 2;

    if (Vox::Keyboard::KeyDownOrHold(env, Vox::KeyboardKey::LeftShift))
        dy -= 2;

    glm::mat4 view = this->view();

    glm::vec3 forward(view[0][2], view[1][2], view[2][2]);
    glm::vec3 up(view[0][1], view[1][1], view[2][1]);
    glm::vec3 strafe(view[0][0], view[1][0], view[2][0]);

    this->position += ((-dz * forward) + (dy * up) + (dx * strafe)) * speed;
}