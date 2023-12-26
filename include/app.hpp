#pragma once

#include "window.hpp"

namespace lve {
    class MyApp{
        public:
            static constexpr int WIDTH= 1080;
            static constexpr int HIGHT= 800;

            void run();

        private:
            LveWindow myWindow{WIDTH, HIGHT, "Hello Vulkan!"};
    };

}   
