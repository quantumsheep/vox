#include <vox/vox.hpp>

int main()
{
    std::unique_ptr<Vox::Environment> env = Vox::Init(1280, 720, "First Person Camera", true);
    if (env == nullptr)
        return 1;

    Vox::Shader standard("shaders/standard.vertex.glsl", "shaders/standard.fragment.glsl");

    while (env->next_frame())
    {
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Vox::UI::NewFrame();

        Vox::UI::Window::Create("Debug", [&] {
            Vox::UI::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / env->ui_io.Framerate, env->ui_io.Framerate);

            Vox::UI::Separator();

            static bool wireframe = false;
            Vox::UI::Checkbox("Wireframe", &wireframe);

            glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
        });

        std::vector<Vox::Vertex> vertices = {
            {glm::vec3(-0.5f, -0.5f, -0.5f)},
            {glm::vec3(0.5f, -0.5f, -0.5f)},
            {glm::vec3(0.5f, 0.5f, -0.5f)},
            {glm::vec3(0.5f, 0.5f, -0.5f)},
            {glm::vec3(-0.5f, 0.5f, -0.5f)},
            {glm::vec3(-0.5f, -0.5f, -0.5f)},

            {glm::vec3(-0.5f, -0.5f, 0.5f)},
            {glm::vec3(0.5f, -0.5f, 0.5f)},
            {glm::vec3(0.5f, 0.5f, 0.5f)},
            {glm::vec3(0.5f, 0.5f, 0.5f)},
            {glm::vec3(-0.5f, 0.5f, 0.5f)},
            {glm::vec3(-0.5f, -0.5f, 0.5f)},

            {glm::vec3(-0.5f, 0.5f, 0.5f)},
            {glm::vec3(-0.5f, 0.5f, -0.5f)},
            {glm::vec3(-0.5f, -0.5f, -0.5f)},
            {glm::vec3(-0.5f, -0.5f, -0.5f)},
            {glm::vec3(-0.5f, -0.5f, 0.5f)},
            {glm::vec3(-0.5f, 0.5f, 0.5f)},

            {glm::vec3(0.5f, 0.5f, 0.5f)},
            {glm::vec3(0.5f, 0.5f, -0.5f)},
            {glm::vec3(0.5f, -0.5f, -0.5f)},
            {glm::vec3(0.5f, -0.5f, -0.5f)},
            {glm::vec3(0.5f, -0.5f, 0.5f)},
            {glm::vec3(0.5f, 0.5f, 0.5f)},

            {glm::vec3(-0.5f, -0.5f, -0.5f)},
            {glm::vec3(0.5f, -0.5f, -0.5f)},
            {glm::vec3(0.5f, -0.5f, 0.5f)},
            {glm::vec3(0.5f, -0.5f, 0.5f)},
            {glm::vec3(-0.5f, -0.5f, 0.5f)},
            {glm::vec3(-0.5f, -0.5f, -0.5f)},

            {glm::vec3(-0.5f, 0.5f, -0.5f)},
            {glm::vec3(0.5f, 0.5f, -0.5f)},
            {glm::vec3(0.5f, 0.5f, 0.5f)},
            {glm::vec3(0.5f, 0.5f, 0.5f)},
            {glm::vec3(-0.5f, 0.5f, 0.5f)},
            {glm::vec3(-0.5f, 0.5f, -0.5f)},
        };

        static Vox::Object cube(vertices);

        Vox::UI::Window::Create("Cube Control", [&] {
            Vox::UI::Text("Position");
            Vox::UI::DragFloat("pos x", &cube.position.x, 0.01f);
            Vox::UI::DragFloat("pos y", &cube.position.y, 0.01f);
            Vox::UI::DragFloat("pos z", &cube.position.z, 0.01f);

            Vox::UI::Separator();

            Vox::UI::Text("Rotation");
            Vox::UI::DragFloat("rot x", &cube.rotation.x, 0.3f);
            Vox::UI::DragFloat("rot y", &cube.rotation.y, 0.3f);
            Vox::UI::DragFloat("rot z", &cube.rotation.z, 0.3f);

            Vox::UI::Separator();

            Vox::UI::Text("Scale");
            Vox::UI::DragFloat("scl x", &cube.scale.x, 0.1f);
            Vox::UI::DragFloat("scl y", &cube.scale.y, 0.1f);
            Vox::UI::DragFloat("scl z", &cube.scale.z, 0.1f);
        });

        static Vox::Camera camera((float)env->width, (float)env->height, glm::vec3(0.0f, 0.0f, -10.0f));

        Vox::UI::Window::Create("Camera Control", [&] {
            Vox::UI::Text("Position");
            Vox::UI::DragFloat("pos x", &camera.position.x, 0.01f);
            Vox::UI::DragFloat("pos y", &camera.position.y, 0.01f);
            Vox::UI::DragFloat("pos z", &camera.position.z, 0.01f);

            Vox::UI::Separator();

            Vox::UI::Text("Rotation");
            Vox::UI::DragFloat("rot x", &camera.rotation.x, 0.3f);
            Vox::UI::DragFloat("rot y", &camera.rotation.y, 0.3f);
            Vox::UI::DragFloat("rot z", &camera.rotation.z, 0.3f);

            Vox::UI::Separator();

            Vox::UI::Text("Properties");
            Vox::UI::DragFloat("fov", &camera.fov, 0.1f);
            Vox::UI::DragFloat("near", &camera.near, 0.1f);
            Vox::UI::DragFloat("far", &camera.far, 0.1f);

            Vox::UI::Separator();
            Vox::UI::Text("Front");
            Vox::UI::Text("%s", std::to_string(cos(glm::radians(camera.rotation.y)) * cos(glm::radians(camera.rotation.x))).c_str());
            Vox::UI::Text("%s", std::to_string(sin(glm::radians(camera.rotation.y))).c_str());
            Vox::UI::Text("%s", std::to_string(cos(glm::radians(camera.rotation.y)) * sin(glm::radians(camera.rotation.x))).c_str());
        });

        Vox::UI::Render();

        standard.use();
        standard.set_vec3("color", glm::vec3(1.0f, 0.0f, 0.0f));
        standard.set_mat4("projection", camera.projection());
        standard.set_mat4("view", camera.view());
        standard.set_mat4("model", cube.model());

        cube.draw();

        Vox::UI::Draw();

        env->update_viewport();
        env->swap_buffers();
    }

    return 0;
}
