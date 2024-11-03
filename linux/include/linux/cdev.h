//
// Created by denis on 29/10/24.
//

#ifndef CDEV_H
#define CDEV_H

#include "device.h"

struct cdev {
    struct kobject kobj;
    struct module *owner;
    const struct file_operations *ops;
    struct list_head list;
    dev_t dev;
    unsigned int count;
};

#endif //CDEV_H
