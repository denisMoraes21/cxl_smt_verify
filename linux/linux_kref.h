//
// Created by denis on 28/10/24.
//

#ifndef LINUX_KREF_H
#define LINUX_KREF_H

struct kref {
    refcount_t refcount;
};

#endif //LINUX_KREF_H
