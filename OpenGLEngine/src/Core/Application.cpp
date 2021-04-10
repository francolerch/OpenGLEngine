#include "pch.h"
#include "Application.h"
#include "Renderer/Renderer.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

namespace OGLE {
    Application* Application::s_Instance;

    Application::Application()
    {
        OG_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = CreateScope<Window>(WIDTH, HEIGHT);
        Renderer::Init();
    };

    void Application::Run()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplGlfw_InitForOpenGL(m_Window->GetNativeWindow(), true);
        ImGui_ImplOpenGL3_Init("#version 410");

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
            for (Layer* layer : m_LayerStack)
                layer->OnUpdate(deltaTime);

            // render
            // ------
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            ImGuiIO& io = ImGui::GetIO();
            io.DisplaySize = ImVec2(WIDTH, HEIGHT);

            static bool show = true;
            ImGui::ShowDemoWindow(&show);

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            m_Window->OnUpdate();
        }

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

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
