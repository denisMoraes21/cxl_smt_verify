//
// Created by denis on 28/10/24.
//

#ifndef CXLMEM_H
#define CXLMEM_H

#include "../../include/linux/device.h"

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

#endif //CXLMEM_H
