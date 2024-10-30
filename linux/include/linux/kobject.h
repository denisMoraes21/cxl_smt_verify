//
// Created by denis on 30/10/24.
//

#ifndef KOBJECT_H
#define KOBJECT_H

struct kobject {
    const char *name;
    struct list_head *next, *prev;                  // CHANGE: struct list_head entry;
    struct kobject *parent;
    struct kset *kset;
    const struct kobj_type *ktype;
    struct kernfs_node *sd;
    int kref;                                       // CHANGE: struct kref kref;

    unsigned int state_initialized:1;
    unsigned int state_in_sysfs:1;
    unsigned int state_add_uevent_sent:1;
    unsigned int state_remove_uevent_sent:1;
    unsigned int uevent_suppress:1;

// #ifdef CONFIG_DEBUG_KOBJECT_RELEASE
//     struct delayed_work	release;                // Non-essential
// #endif
};

#endif //KOBJECT_H
