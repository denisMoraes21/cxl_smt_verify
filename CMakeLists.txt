cmake_minimum_required(VERSION 3.29)
project(cxl_esbmc)

set(CMAKE_CXX_STANDARD 20)

add_executable(cxl_esbmc main.cpp
        linux/include/linux/device.h
        examples/Clang/clang_example.cpp
        examples/Others/clang_example.c
        examples/GCC/gcc_example.cpp
        linux/drivers/cxl/cxlmem.h
        linux/linux_kobject.h
        linux/linux_types.h
        linux/linux_kref.h
        linux/linux_refcount.h
        linux/include/linux/cdev.h
)
