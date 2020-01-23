#include "Window.h"

namespace OGLE {

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    static void error_callback(int error, const char* description)
    {
        OG_ERROR("GLFW Error ({0}): {1}", error, description);
    }

Window::Window(const unsigned int width, const unsigned int height, const std::string& title)
    {
        if (!glfwInit())
            exit(EXIT_FAILURE);

        m_Window = (glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), title.c_str(), NULL, NULL));
        OG_ASSERT(m_Window, "Failed to create window!");

        glfwSetErrorCallback(error_callback);
        glfwSetKeyCallback(m_Window, key_callback);

        if (!m_Window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }


        glfwMakeContextCurrent(m_Window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        OG_ASSERT(status, "Failed to initialize Glad!");
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

        OG_INFO("OpenGL Info:");
        OG_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
        OG_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        OG_INFO("  Version: {0}", glGetString(GL_VERSION));

        //glfwSetFramebufferSizeCallback(m_Window, FramebufferSizeCallback);
        //glfwSetScrollCallback(m_Window, ScrollCallback);
        //glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        glEnable(GL_DEPTH_TEST);
        glfwSwapInterval(1);

    }

    Window::~Window()
    {
        glfwDestroyWindow(m_Window);
    }

    int32_t Window::GetKey(int32_t key) 
    {
        return glfwGetKey(m_Window, key);
    }

    int32_t Window::GetMouseButton(int32_t button)
    {
        return glfwGetMouseButton(m_Window, button);
    }

    std::pair<float, float> Window::GetMousePos() const
    {
        double xpos, ypos;
        glfwGetCursorPos(m_Window, &xpos, &ypos);
		return { (float)xpos, (float)ypos };
    }

    bool Window::ShouldClose() const
    {
        return glfwWindowShouldClose(m_Window);
    }

    void Window::OnUpdate() const 
    {
        /*if (Input::IsKeyPressed(OGLE_KEY_ESCAPE))
		{
			auto window = Application::Get().GetWindow();
			glfwSetWindowShouldClose(window, true);
		}*/
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }
}