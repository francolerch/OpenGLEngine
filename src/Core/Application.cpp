#include "pch.h"
#include "Application.h"
#include "Renderer/Shader.h"
#include "Model.h"
//#include "Texture.h"
#include "Entities/PerspectiveCamera.h"

namespace OGLE {
    Application* Application::s_Instance;

    Application::Application()
    {
        OG_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = CreateScope<Window>();
        //m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));
        Scope<PerspectiveCamera> camera = CreateScope<PerspectiveCamera>();
        m_Entities.push_back(camera.get());
    };

    void Application::Run()
    {
         float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
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

        //Shader lightingShader("res/shaders/LightingMap.glsl");
        Shader lampShader("res/shaders/Lamp.glsl");
        Shader ourShader("res/shaders/model_loading.glsl");

        Model ourModel("res/models/nanosuit/nanosuit.obj");

        //Texture diffuseMap("res/textures/container2.png");
        //Texture specularMap("res/textures/container2_specular.png");

        unsigned int VBO, cubeVAO;
        glGenVertexArrays(1, &cubeVAO);
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindVertexArray(cubeVAO);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // normal attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        // uv coord
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (6* sizeof(float)));
        glEnableVertexAttribArray(2);

        // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
        unsigned int lightVAO;
        glGenVertexArrays(1, &lightVAO);
        glBindVertexArray(lightVAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // note that we update the lamp's position attribute's stride to reflect the updated buffer data
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glm::vec3 lightPos(1.2f, 0.0f, 2.0f);

        while (!m_Window->ShouldClose())
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
            m_Entities[0]->OnUpdate(deltaTime);

            // render
            // ------
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            ourShader.Bind();

            // view/projection transformations
            glm::mat4 projection = glm::perspective(glm::radians(60.f), WIDTH / HEIGHT, 0.1f, 100.0f);
            glm::mat4 view;// = glm::lookAt(m_Camera.GetCameraPos(), m_Camera.GetCameraFront() + m_Camera.GetCameraPos(), m_Camera.GetCameraUp());
            ourShader.SetUniformMat4f("projection", projection);
            ourShader.SetUniformMat4f("view", view);

            // render the loaded model
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.0f, -1.75f, 0.0f)); // translate it down so it's at the center of the scene
            model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));	// it's a bit too big for our scene, so scale it down
            ourShader.SetUniformMat4f("model", model);

            // be sure to activate shader when setting uniforms/drawing objects
            //ourShader.Bind();
            ourShader.SetUniform3f("objectColor", 1.0f, 0.7f, 0.3f);
            ourShader.SetUniform3f("lightColor", 1.0f, 1.0f, 1.0f);
            ourShader.SetUniform3f("lightPos", lightPos.x, lightPos.y, lightPos.z);
            //ourShader.SetUniform3f("viewPos", m_Camera.GetCameraPos().x, m_Camera.GetCameraPos().y, m_Camera.GetCameraPos().z);
            ourShader.SetUniform3f("viewPos", 1.f, 1.f, 1.f);

            // material properties
            //diffuseMap.Bind(0);
            //specularMap.Bind(1);
            //lightingShader.SetUniform1i("material.diffuse", 0);
            //lightingShader.SetUniform1i("material.specular", 1);
            ourShader.SetUniform1f("material.shininess", 32.0f);

            // light properties
            ourShader.SetUniform3f("light.direction", -0.2f, -1.0f, -0.3f);
            ourShader.SetUniform3f("light.ambient", 0.3f, 0.3f, 0.3f);
            ourShader.SetUniform3f("light.diffuse", 0.5f, 0.5f, 0.5f);
            ourShader.SetUniform3f("light.specular", 1.0f, 1.0f, 1.0f); 

            ourShader.SetUniform1f("light.constant", 1.0f);
            ourShader.SetUniform1f("light.linear", 0.09f);
            ourShader.SetUniform1f("light.quadratic", 0.032f);

            // view/projection transformations
            ourShader.SetUniformMat4f("projection", projection);
            ourShader.SetUniformMat4f("view", view);

            // world transformation
            model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.f, 1.f, 0.f));
            ourShader.SetUniformMat4f("model", model);

            ourModel.Draw(ourShader);

/*
        //glBindTexture(GL_TEXTURE_2D, 0);
        // also draw the lamp object
        lampShader.Bind();
        lampShader.SetUniformMat4f("projection", projection);
        lampShader.SetUniformMat4f("view", view);
        model = glm::mat4(1.0f);
        model = glm::translate(model, lightPos);
        model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
        lampShader.SetUniformMat4f("model", model);

        glBindVertexArray(lightVAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);



*/
            m_Window->SwapBuffers();
        }
    }

    Application::~Application() 
    {
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