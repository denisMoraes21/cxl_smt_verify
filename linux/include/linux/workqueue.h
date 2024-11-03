//
// Created by denis on 03/11/24.
//

#ifndef WORKQUEUE_H
#define WORKQUEUE_H

#include "timer_types.h"

struct delayed_work {
    struct work_struct work;
    struct timer_list timer;
    struct workqueue_struct *wq;
    int cpu;
// #ifdef CONFIG_LOCKDEP
//     struct lockdep_map	lockdep_map;
// #endif
};

#endif //WORKQUEUE_H
