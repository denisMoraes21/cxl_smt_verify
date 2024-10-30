//
// Created by denis on 30/10/24.
//

#ifndef MUTEX_TYPES_H
#define MUTEX_TYPES_H

struct mutex {
    long long owner;                                                    // CHANGE: atomic_long_t owner
    int lock;                                                           // CHANGE: raw_spinlock_t wait_lock;
    // #ifdef CONFIG_MUTEX_SPIN_ON_OWNER
    //     struct optimistic_spin_queue osq; /* Spinner MCS lock */     // Non-essential
    // #endif
    struct list_head *next, *prev;                                      // CHANGE: struct list_head	wait_list;
    // #ifdef CONFIG_DEBUG_MUTEXES
    //     void			*magic;                                         // Non-essential
    // #endif
    // #ifdef CONFIG_DEBUG_LOCK_ALLOC
    //     struct lockdep_map	dep_map;                                // Non-essential
    // #endif
};

#endif //MUTEX_TYPES_H
