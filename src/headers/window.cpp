#include <headers/window.h>

namespace graphics {

    Window::Window(int width, int height, const char* title) {

        Width = width;
        Height = height;
        Title = title;

        if (!init()) {

            glfwTerminate();

        }

    }

    bool Window::init() {

        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        Canvas = glfwCreateWindow(Width, Height, Title, NULL, NULL);
        if (!Canvas) {

            std::cout << "Failed to create window" << std::endl;
            return false;

        }
        glfwMakeContextCurrent(Canvas);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {

            std::cout << "Failed to intialize glad" << std::endl;
            return false;

        }

        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

        return true;

    }

    bool Window::closed() {

        return glfwWindowShouldClose(Canvas);

    }

    void Window::clean() {

        glClear(GL_COLOR_BUFFER_BIT);

    }

    void Window::update() {

        glfwSwapBuffers(Canvas);
        glfwPollEvents();

    }

}