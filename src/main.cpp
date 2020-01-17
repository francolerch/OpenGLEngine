#include "pch.h"
#include "RendererCore.h"
#include "linmath.h"

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"

float vertices[] = {
    -1.00f, -0.50f, 0.0f,
    -0.50f,  0.50f, 0.0f,
     0.00f, -0.50f, 0.0f,
     0.50f,  0.50f, 0.0f,
     1.00f, -0.50f, 0.0f
};

unsigned int indices[] = {
    0, 1, 2,
    2, 3, 4
};

static void error_callback(int error, const char* description)
{
    std::cerr << "(" << error << ")" << "Error: %s\n" << description << std::endl;
}
 
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
 
int main(void)
{
    GLFWwindow* window;
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;
    GLfloat vtime_location;
 
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
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    Shader shader("res/shaders/FlatColor.glsl");
    shader.Bind();
    VertexArray va;
    VertexBuffer vb(vertices, 5 * 3 * sizeof(float));
    va.AddBuffer(vb);
    IndexBuffer ib(indices, 6);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while (!glfwWindowShouldClose(window))
    {
        glDrawElements(GL_TRIANGLES, std::size(indices), GL_UNSIGNED_INT, 0);
 
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}