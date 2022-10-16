#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace graphics {

    class Window {

        private:
            int Width, Height;
            const char* Title;
            GLFWwindow* Canvas;

        public:
            Window(int width, int height, const char* title);
            bool closed();
            void clean();
            void update();

        private:
            bool init();

    };

}

#endif