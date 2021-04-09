#include "pch.h"
#include "Application.h"
#include "Core/Model.h"

namespace OGLE {
    Application* Application::s_Instance;

    Application::Application()
    {
        OG_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = CreateScope<Window>();
        Renderer::Init();
    };

    void Application::Run()
    {
        Model model("res/models/me/untitled.obj");

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
            m_Camera.OnUpdate(deltaTime);
            for (Layer* layer : m_LayerStack)
                layer->OnUpdate(deltaTime);

            // render
            // ------
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glm::mat4 transform(1.0);

            model.Draw();

            m_Window->OnUpdate();
        }
    }

    Application::~Application() 
    {
        Renderer::Shutdown();
        
        glfwTerminate();
        exit(EXIT_SUCCESS);
    }

    void Application::PushLayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
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
