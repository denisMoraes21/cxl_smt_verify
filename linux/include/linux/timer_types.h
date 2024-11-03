//
// Created by denis on 03/11/24.
//

#ifndef TIMER_TYPES_H
#define TIMER_TYPES_H

#include "types.h"

struct timer_list {
    struct hlist_node	entry;
    unsigned long		expires;
    void			(*function)(struct timer_list *);
    u32			flags;

#ifdef CONFIG_LOCKDEP
    struct lockdep_map	lockdep_map;
#endif
};

#endif //TIMER_TYPES_H
