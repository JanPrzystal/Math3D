cmake_minimum_required(VERSION 3.18)

set(CMAKE_C++_STANDARD 17)

project(math3D CXX)

add_library(math3D 
    ./math/Vector3.cpp 
    ./math/Vector4.cpp 
    ./math/Matrix4.cpp
    ./rendering_utils/Camera.cpp
    ./rendering_utils/Mesh.cpp
    ./rendering_utils/Triangle.cpp
)

target_include_directories(math3D PUBLIC
    ./math
    ./rendering_utils    
    ./
)
