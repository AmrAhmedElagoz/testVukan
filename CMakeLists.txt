cmake_minimum_required(VERSION 3.17)

if(WIN32)
    message(STATUS "Building for Windows....")
endif()

# if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
#     message(STATUS "Building in Debug mode")
# endif()

project(testVulkan LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    message(STATUS "Building with MSVC...")
    set(_CRT_SECURE_NO_WARNINGS 1)
    set(CURL_STATICLIB 1)
endif()


FILE(GLOB_RECURSE SOURCES src/*.cpp)
FILE(GLOB_RECURSE HEADERS include/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Externals/vulkan/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/Externals/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Externals/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB VULKANLIB ${CMAKE_CURRENT_SOURCE_DIR}/Externals/vulkan/Lib/*.lib)
file(GLOB GLFWLIB ${CMAKE_CURRENT_SOURCE_DIR}/Externals/glfw/lib-vc2022/*.lib)

target_link_libraries(${PROJECT_NAME} PRIVATE
    ${VULKANLIB}
    ${GLFWLIB}
)

target_compile_options(${CMAKE_PROJECT_NAME}
    PRIVATE $<$<COMPILE_LANGUAGE:CXX>: >
)

