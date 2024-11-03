//
// Created by denis on 03/11/24.
//

#ifndef SPINLOCK_TYPES_RAW_H
#define SPINLOCK_TYPES_RAW_H

#include "spinlock_types_up.h"

typedef struct raw_spinlock {
    arch_spinlock_t raw_lock;
// #ifdef CONFIG_DEBUG_SPINLOCK
//     unsigned int magic, owner_cpu;
//     void *owner;
// #endif
// #ifdef CONFIG_DEBUG_LOCK_ALLOC
//     struct lockdep_map dep_map;
// #endif
} raw_spinlock_t;

#endif //SPINLOCK_TYPES_RAW_H
