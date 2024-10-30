//
// Created by denis on 28/10/24.
//

#ifndef LINUX_REFCOUNT_H
#define LINUX_REFCOUNT_H

typedef struct refcount_struct {
    atomic_t refs;
} refcount_t;

#endif //LINUX_REFCOUNT_H
