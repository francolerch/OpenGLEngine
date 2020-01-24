#include "pch.h"
#include "Application.h"
#include "Renderer/Shader.h"
//#include "Texture.h"
#include "Renderer/VertexArray.h"
#include "Entities/PerspectiveCamera.h"
#include "Renderer/Renderer.h"
#include "Renderer/VertexBufferLayout.h"
#include "Renderer/IndexBuffer.h"

namespace OGLE {
    Application* Application::s_Instance;

    Application::Application()
    {
        OG_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = CreateScope<Window>();
        //m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));
        Renderer::Init();
    };

    void Application::Run()
    {
         float vertices[] = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left 
        };
        unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,  // first Triangle
            1, 2, 3   // second Triangle
        };

        Ref<Shader> shader = CreateRef<Shader>("res/shaders/FlatColor.glsl");
        Ref<VertexArray> vao = CreateRef<VertexArray>();
        VertexBuffer vbo(vertices, sizeof(vertices));
        IndexBuffer ib(indices, sizeof(indices));
        VertexBufferLayout layout;
        layout.Push(3);
        vao->AddBuffer(vbo, layout);

        //PerspectiveCamera camera;

        while (!m_Window->ShouldClose())
        {
            // per-frame time logic
            // ---------------------
            float currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            // input
            // ---------------------

            // Update
            //m_Entities[0]->OnUpdate(deltaTime);
            //camera.OnUpdate(deltaTime);

            // render
            // ------
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glm::mat4 transform(1.0);
            shader->Bind();

            Renderer::Submit(shader, vao, transform);

            m_Window->OnUpdate();
        }
    }

    Application::~Application() 
    {
        Renderer::Shutdown();
        
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }

    void Application::MouseCallback(GLFWwindow* m_Window, double xpos, double ypos)
    {
    }

    void Application::ScrollCallback(GLFWwindow* m_Window, double xoffset, double yoffset)
    {
    /*    if (fov >= 1.0f && fov <= 45.0f)
            fov -= yoffset;s
        if (fov <= 1.0f)
            fov = 1.0f;
        if (fov >= 45.0f)
            fov = 45.0f;
    */}

    void Application::FramebufferSizeCallback(GLFWwindow* m_Window, int width, int height)
    {
    }
}