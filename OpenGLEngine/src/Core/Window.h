#pragma once
#include "Core.h"
#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace OGLE {
    class Window
    {
    private:
        GLFWwindow* m_Window;
    public:
        Window(const unsigned int width = 800, const unsigned int height = 600, const std::string& title = "OpenGL Engine");
        ~Window();

        GLFWwindow* GetNativeWindow() { return m_Window; };

        int32_t GetKey(int32_t key);
        int32_t GetMouseButton(int32_t button);
        std::pair<float, float> GetMousePos() const;
        bool ShouldClose() const;
        void OnUpdate() const;
    };
}