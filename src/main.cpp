#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Texture.h"
#include "Quad.h"

int main()
{
    glfwInit();

    GLFWwindow *window = glfwCreateWindow(800, 600, "Medical Viewer", NULL, NULL);
    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glViewport(0, 0, 800, 600);

    Shader shader("src/shaders/image.vert", "src/shaders/image.frag");
    Texture image("src/assets/brain_slice.png");
    Quad quad;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        glActiveTexture(GL_TEXTURE0);
        image.bind();
        shader.setInt("u_image", 0);

        quad.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}