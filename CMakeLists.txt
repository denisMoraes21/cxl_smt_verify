cmake_minimum_required(VERSION 3.29)
project(cxl_esbmc)

set(CMAKE_CXX_STANDARD 20)

add_executable(cxl_esbmc main.cpp
        linux/include/linux/device.h
        bear_examples/Clang/clang_example.cpp
        bear_examples/GCC/gcc_example.cpp
        linux/drivers/cxl/cxlmem.h
        linux/include/linux/cdev.h
        linux/include/linux/kobject.h
        linux/include/linux/mutex.h
        linux/include/linux/mutex_types.h
        linux/include/linux/types.h
        linux/include/linux/kref.h
        linux/include/linux/refcount.h
        linux/include/linux/pm.h
        linux/include/acpi/actypes.h
        linux/include/linux/pm.h
        linux/include/linux/spinlock_types.h
        linux/include/linux/spinlock_types_raw.h
        linux/include/linux/spinlock_types_up.h
        linux/include/asm-generic/device.h
        linux/include/linux/device/class.h
        linux/include/linux/uidgid_types.h
        linux/include/uapi/asm_generic/posix_types.h
        linux/include/linux/workqueue_types.h
        linux/include/asm-generic/int-ll64.h
        linux/include/asm-generic/int_l64.h
        linux/drivers/cxl/pmem.c
        linux/include/linux/workqueue.h
        linux/include/linux/timer_types.h
        linux/include/linux/range.h
        linux/include/linux/node.h
        linux/drivers/cxl/cxl.h
)
