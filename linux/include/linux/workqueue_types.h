//
// Created by denis on 03/11/24.
//

#ifndef WORKQUEUE_TYPES_H
#define WORKQUEUE_TYPES_H

#include "types.h"

typedef void (*work_func_t)(struct work_struct *work);

struct work_struct {
    atomic_long_t data;
    struct list_head entry;
    work_func_t func;
// #ifdef CONFIG_LOCKDEP
//     struct lockdep_map lockdep_map;
// #endif
};

#endif //WORKQUEUE_TYPES_H
