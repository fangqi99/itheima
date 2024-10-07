cmake_minimum_required(VERSION 3.0)
project(排序案例)

# 设置头文件的包含路径
include_directories(STL/案例/排序案例/include)

# 添加源文件
#set(SOURCE_FILES src/*.cpp
#                   main.cpp)
# add_executable(main ${SOURCE_FILES})


# 查找所有源文件
file(GLOB SOURCES "src/*.cpp")
add_executable(main main.cpp ${SOURCES})
    