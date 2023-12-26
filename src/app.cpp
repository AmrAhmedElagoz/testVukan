#include <app.hpp>

namespace lve {

    void MyApp::run(){

        while(!myWindow.shouldClose()){
            // glfwPollEvents checks any window events; while our window doesn't want to
            // close then pull window events (user click Esc to dismiss window for example)
            glfwPollEvents();
        }
    }
}