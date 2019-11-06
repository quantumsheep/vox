#include <vox/vox.hpp>

int main()
{
    std::unique_ptr<Vox::Environment> env = Vox::Init(1280, 720, "First Person Camera", true);
    if (env == nullptr)
        return 1;

    while (env->next_frame())
    {
        Vox::UI::NewFrame();

        Vox::UI::Window::Create("Debug", [&] {
            Vox::UI::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / env->ui_io.Framerate, env->ui_io.Framerate);
        });

        Vox::UI::Render();
        env->update_viewport();

        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Vox::UI::Draw();

        env->swap_buffers();
    }

    return 0;
}
