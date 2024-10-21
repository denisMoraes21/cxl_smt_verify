cmake_minimum_required(VERSION 3.29)
project(cxl_esbmc)

set(CMAKE_CXX_STANDARD 20)

add_executable(cxl_esbmc main.cpp
        cxl_memdev_structs.h
        linux_device_structs.h)
