#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    GLFWwindow* window;

    if (!glfwInit()) {
        cout << "Erreur lors de l'initialisation de GLFW" << endl;
        return -1;
    }

    window = glfwCreateWindow(640, 480, "Arcade", NULL, NULL);
    if (!window) {
        glfwTerminate();
        cout << "Erreur lors de la création de la fenêtre GLFW" << endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width, height, 0, 0, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Dessiner ici

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
