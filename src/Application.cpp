#include "pch.h"
#include "Application.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"

namespace OGLE {
    Application* Application::s_Instance;

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    static void error_callback(int error, const char* description)
    {
        OG_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Application::Application()
    {
        OG_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        if (!glfwInit())
            exit(EXIT_FAILURE);

        m_Window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGLEngine", NULL, NULL);
        //m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));
    };

    Application::~Application()
    {
    }

    void Application::Run()
    {

        float vertices[] = {
            // positions            // colors           // texture coords
            -1.00f, -1.00f, -.5f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
             1.00f, -1.00f, -.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
             1.00f,  1.00f, -.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
            -1.00f,  1.00f, -.5f,   0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
             0.00f,  0.00f,  1.0f,  0.0f, 0.0f, 1.0f,   0.5f, 1.0f,

        };

        unsigned int indices[] = {
            0, 1, 2,
            2, 3, 0,
            0, 1, 4,
            1, 2, 4,
            2, 3, 4,
            3, 0, 4
        };

        glm::vec3 cubePositions[] = {
          glm::vec3(0.0f,  0.0f,  0.0f),
          glm::vec3(2.0f,  5.0f, -15.0f),
          glm::vec3(-1.5f, -2.2f, -2.5f),
          glm::vec3(-3.8f, -2.0f, -12.3f),
          glm::vec3(2.4f, -0.4f, -3.5f),
          glm::vec3(-1.7f,  3.0f, -7.5f),
          glm::vec3(1.3f, -2.0f, -2.5f),
          glm::vec3(1.5f,  2.0f, -2.5f),
          glm::vec3(1.5f,  0.2f, -1.5f),
          glm::vec3(-1.3f,  1.0f, -1.5f)
        };


        glfwSetErrorCallback(error_callback);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (!m_Window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwSetKeyCallback(m_Window, key_callback);

        glfwMakeContextCurrent(m_Window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        OG_ASSERT(status, "Failed to initialize Glad!");
       

        OG_INFO("OpenGL Info:");
        OG_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
        OG_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        OG_INFO("  Version: {0}", glGetString(GL_VERSION));

        //glfwSetFramebufferSizeCallback(m_Window, FramebufferSizeCallback);
        //glfwSetScrollCallback(m_Window, ScrollCallback);
        glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        glEnable(GL_DEPTH_TEST);
        glfwSwapInterval(1);

        Shader shader("res/shaders/DepthTesting.glsl");
        shader.Bind();
        VertexArray va;
        VertexBuffer vb(vertices, std::size(vertices) * sizeof(vertices[0]));
        VertexBufferLayout layout;
        layout.Push<float>(3); // position
        layout.Push<float>(3); // colors
        layout.Push<float>(2); // tex coord

        va.AddBuffer(vb, layout);
        IndexBuffer ib(indices, std::size(indices));
        Texture tex("res/textures/wall.jpg");
    
        glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(-1.0f, 1.0f, 0.0f));


        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

        glm::mat4 proj;
        proj = glm::perspective(glm::radians(60.f), WIDTH / HEIGHT, 0.1f, 100.0f);

        while (!glfwWindowShouldClose(m_Window))
        {
            // per-frame time logic
            // ---------------------
            float currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            // input
            // ---------------------
            //glfwPollEvents();

            // Update
            m_Camera.OnUpdate(deltaTime);

            // render
            // ---------------------
            glm::mat4 trans = glm::mat4(1.0f);
            trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
            trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.5f, 0.7f, 1.0f));


            glm::mat4 view = glm::lookAt(m_Camera.GetCameraPos(), m_Camera.GetCameraFront() + m_Camera.GetCameraPos(), m_Camera.GetCameraUp());

            glClearColor(.0f, 0.0f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, tex.Get());



            float greenValue = 1.f;//(sin(startTime) / 2.0f) + 0.5f;



            shader.SetUniformMat4f("u_Transform", trans);
            shader.SetUniform4f("u_Color", 1.0f, greenValue, 1.0f, 1.0f);

            va.Bind();
            for (unsigned int i = 0; i < 10; i++)
            {
                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, cubePositions[i]);
                float angle = 20.0f * i;
                model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
                glm::mat4 mvp = proj * view * model;

                shader.SetUniformMat4f("u_Mvp", mvp);

                glDrawElements(GL_TRIANGLES, std::size(indices), GL_UNSIGNED_INT, 0);
            }


            glfwSwapBuffers(m_Window);
            glfwPollEvents();
        }

        glfwDestroyWindow(m_Window);

        glfwTerminate();
        exit(EXIT_SUCCESS);
    }

    void Application::MouseCallback(GLFWwindow* m_Window, double xpos, double ypos)
    {
    /*    if (firstMouse)
        {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }

        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos;
        lastX = xpos;
        lastY = ypos;

        float sensitivity = 0.1;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        yaw += xoffset;
        pitch += yoffset;

        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        glm::vec3 direction;
        direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        direction.y = sin(glm::radians(pitch));
        direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFront = glm::normalize(direction);*/
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