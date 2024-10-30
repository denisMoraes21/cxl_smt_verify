//
// Created by denis on 28/10/24.
// kobjects are used to control access to a larger, domain-specific object
//

#ifndef LINUX_KOBJECT_H
#define LINUX_KOBJECT_H

#include "linux_types.h"

#define KOBJECT_NAME "name"

struct kobject {
    const char *name = KOBJECT_NAME ;
    struct list_head entry{};
    struct kobject *parent;
    struct kset *kset;
    const struct kobj_type *sd;
    struct kref kref;
};

#endif //LINUX_KOBJECT_H
