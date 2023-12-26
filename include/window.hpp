#pragma once
// include the vulkan headers only if GLFW_INCLUDE_VULKAN macro is defined
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

namespace lve {

    class LveWindow{
        public:
            LveWindow(int w, int h, std::string name);
            ~LveWindow();

            LveWindow(const LveWindow &) = delete;
            LveWindow &operator=(const LveWindow &) = delete;

            bool shouldClose() { return glfwWindowShouldClose(window); }

        private:
            void initWindow();
            int height;
            int width;
            std::string winName;
            
            GLFWwindow *window;

    };
}