cmake_minimum_required(VERSION 3.0)
project(评委打分)

# 设置头文件的包含路径
include_directories(include)

# 添加源文件
#set(SOURCE_FILES src/*.cpp)
# add_executable(main main.cpp
#                     src/Person.cpp)


# 查找所有源文件
file(GLOB SOURCES "src/*.cpp")
add_executable(main main.cpp ${SOURCES})
    