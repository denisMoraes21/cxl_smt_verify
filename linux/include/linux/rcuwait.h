//
// Created by denis on 07/11/24.
//

#ifndef RCUWAIT_H
#define RCUWAIT_H
#include "compiler_types.h"

struct rcuwait {
    struct task_struct __rcu *task;
};

#endif //RCUWAIT_H
