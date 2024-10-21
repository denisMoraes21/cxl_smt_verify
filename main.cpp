#include <iostream>
#include "cxl_memdev_structs.h"

// CXL bus object representing a Type-3 Memory Device
struct clx_memdev {
    struct device dev;
    struct cdev cdev;
    struct cxl_dev_state *cxlds{};
    struct work_struct detach_work;
    struct cxl_nvdimm_bridge *cxl_nvb{};
    struct cxl_port *endpoint{};
    int id = 1;
    int depth = 2;
};

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
