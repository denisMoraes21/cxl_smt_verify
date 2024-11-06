//
// Created by denis on 05/11/24.
//

#ifndef XARRAY_H
#define XARRAY_H

#include "spinlock_types.h"
#include "types.h"
#include "compiler_types.h"

struct xarray {
    spinlock_t	xa_lock;
    gfp_t		xa_flags;
    void __rcu *	xa_head;
};

#endif //XARRAY_H
