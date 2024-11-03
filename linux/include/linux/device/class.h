//
// Created by denis on 03/11/24.
//

#ifndef CLASS_H
#define CLASS_H

#include "types.h"
#include "uidgid_types.h"

struct class_ {
    const char		*name;
    const struct attribute_group **class_groups;
    const struct attribute_group **dev_groups;
    int (*dev_uevent)(const struct device *dev, struct kobj_uevent_env *env);
    char *(*devnode)(const struct device *dev, umode_t *mode);
    void (*class_release)(const struct class_ *class_);
    void (*dev_release)(struct device *dev);
    int (*shutdown_pre)(struct device *dev);
    const struct kobj_ns_type_operations *ns_type;
    const void *(*namespace_)(const struct device *dev);
    void (*get_ownership)(const struct device *dev, kuid_t *uid, kgid_t *gid);
    const struct dev_pm_ops *pm;
};

#endif //CLASS_H
