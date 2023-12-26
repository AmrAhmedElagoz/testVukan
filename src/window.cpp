#include "window.hpp"

namespace lve {

    LveWindow::LveWindow(int w, int h, std::string name) : width{w}, height{h}, winName{name}{
        initWindow();
    }

    LveWindow::~LveWindow(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void LveWindow::initWindow(){
        glfwInit();
        // glfw was designed to creat an OpenGL context when a window is created so
        // glfwWindowHint will tell it to not create OpenGL but a Vulkan, GLFW_NO_API
        // will disable that functionality
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        // another hint to disable the window from being resized after creation
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        // now let's initialize the window with w, h, and name with the glfwCreateWindow
        glfwCreateWindow(width, height, winName.c_str(), nullptr, nullptr);
    };
}