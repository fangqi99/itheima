cmake_minimum_required(VERSION 3.0)
project(itheima)

set(CMAKE_CXX_STANDARD 20)
set(ENV{LC_ALL} "zh_CN.UTF-8")
set(ENV{LANG} "zh_CN.UTF-8")


include_directories(D:/clionproject/itheima/模板/类模板)
add_executable(exampleTemplate 模板/类模板/类模板案例.cpp)
add_executable(itheima main.cpp)
add_executable(main main.cpp)
add_executable(jiujiu jiujiu.cpp)
add_executable(guess_num guess_num.cpp)
add_executable(ds 发工资案例.cpp)