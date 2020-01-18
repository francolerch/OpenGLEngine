#include "pch.h"
#include "RendererCore.h"
//#include "linmath.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"
#include "Math/Mat.h"
#include "Math/Vec4.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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
static void error_callback(int error, const char* description)
{
    std::cerr << "(" << error << ")" << "Error: %s\n" << description << std::endl;
}

float opacity = 0.0f;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    else if (key == GLFW_KEY_UP && action == GLFW_PRESS)
        opacity += 0.5f;
    else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
        opacity -= 0.5f;
}
 
int main(void)
{
    GLFWwindow* window;
 
    glfwSetErrorCallback(error_callback);
 
    if (!glfwInit())
        exit(EXIT_FAILURE);
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
 
    window = glfwCreateWindow(640, 480, "OpenGLEngine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
 
    glfwSetKeyCallback(window, key_callback);
 
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glfwSwapInterval(1);

    Shader shader("res/shaders/ChangingColor.glsl");
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
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    /*Mat4 model = Mat4::Identity();
    model *= Mat4::RotationX(ToRad(-55.f));

    Mat4 view = Mat4::Identity();
    view *= Mat4::Translation(0.f, 0.f, -1.f);

    Mat4 proj = Mat4::Identity();
    proj *= Mat4::Projection(640.f, 480.f, 0.1f, -100.f);
    */
    
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(-1.0f, 1.0f, 0.0f));
    

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    glm::mat4 view = glm::mat4(1.0f);
    // note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -4.0f));

    glm::mat4 proj;
    proj = glm::perspective(glm::radians(65.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    //trans *= scale;
    float startTime = glfwGetTime();
    float elapsedTime = glfwGetTime();
    //glfwSetTime(0.0);

    glEnable(GL_DEPTH_TEST);

   
    while (!glfwWindowShouldClose(window))
    {
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.5f, 0.7f, 1.0f));

        elapsedTime = glfwGetTime();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex.Get());



        float greenValue = (sin(startTime) / 2.0f) + 0.5f;




        shader.SetUniformMat4f("u_Transform", trans);

        shader.SetUniformMat4f("model", model);
        shader.SetUniformMat4f("view", view);
        shader.SetUniformMat4f("projection", proj);

        shader.SetUniform1f("u_Opacity", opacity);
        shader.SetUniform1f("u_Time", startTime);
        shader.SetUniform4f("u_Color", 1.0f, greenValue, 1.0f, 1.0f);

        va.Bind();
        for (unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            shader.SetUniformMat4f("model", model);

            glDrawElements(GL_TRIANGLES, std::size(indices), GL_UNSIGNED_INT, 0);
        }

 
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}