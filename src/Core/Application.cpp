#include "pch.h"
#include "Application.h"
#include "Renderer/Shader.h"
//#include "Texture.h"
#include "Entities/PerspectiveCamera.h"
#include "renderer/Renderer.h"

namespace OGLE {
    Application* Application::s_Instance;

    Application::Application()
    {
        OG_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = CreateScope<Window>();
        //m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));
        Renderer::Init();
        Scope<PerspectiveCamera> camera = CreateScope<PerspectiveCamera>();
        m_Entities.push_back(camera.get());
    };

    void Application::Run()
    {

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

            // render
            // ------
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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