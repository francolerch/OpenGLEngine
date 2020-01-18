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

float vertices[] = {
    // positions            // colors           // texture coords
    -1.00f, -0.50f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
    -0.50f,  0.50f, 0.0f,   0.0f, 1.0f, 0.0f,   0.5f, 1.0f,
     0.00f, -0.50f, 0.0f,   0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
     0.50f,  0.50f, 0.0f,   0.0f, 1.0f, 0.0f,   0.5f, 1.0f,
     1.00f, -0.50f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
};

unsigned int indices[] = {
    0, 1, 2,
    2, 3, 4
};

float texCoords[] = {
    0.0f, 0.0f,  // lower-left corner  
    1.0f, 0.0f,  // lower-right corner
    0.5f, 1.0f   // top-center corner
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
    IndexBuffer ib(indices, 6);
    Texture tex("res/textures/container.jpg");
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex.Get());


        float timeValue = glfwGetTime();
        float greenValue = (sin(timeValue) / 2.0f) + 0.5f;

        shader.SetUniform1f("u_Opacity", opacity);
        shader.SetUniform1f("u_Time", timeValue);
        shader.SetUniform4f("u_Color", 1.0f, greenValue, 1.0f, 1.0f);

        glDrawElements(GL_TRIANGLES, std::size(indices), GL_UNSIGNED_INT, 0);
 
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}