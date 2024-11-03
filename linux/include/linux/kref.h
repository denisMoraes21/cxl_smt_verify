//
// Created by denis on 03/11/24.
//

#ifndef KREF_H
#define KREF_H

#include "refcount.h"

struct kref {
    refcount_t refcount;
};

#endif //KREF_H
