//
// Created by denis on 03/11/24.
//

#ifndef REFCOUNT_H
#define REFCOUNT_H

#include "types.h"

typedef struct refcount_struct {
    atomic_t refs;
} refcount_t;

#endif //REFCOUNT_H
