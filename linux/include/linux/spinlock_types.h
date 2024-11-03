//
// Created by denis on 03/11/24.
//

#ifndef SPINLOCK_TYPES_H
#define SPINLOCK_TYPES_H

#include "spinlock_types_raw.h"

typedef struct spinlock {
    union {
        struct raw_spinlock rlock;

// #ifdef CONFIG_DEBUG_LOCK_ALLOC
// # define LOCK_PADSIZE (offsetof(struct raw_spinlock, dep_map))
//         struct {
//             u8 __padding[LOCK_PADSIZE];
//             struct lockdep_map dep_map;
//         };
// #endif
    };
} spinlock_t;

#endif //SPINLOCK_TYPES_H
