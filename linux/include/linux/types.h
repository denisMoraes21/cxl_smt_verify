//
// Created by denis on 03/11/24.
//

#ifndef TYPES_H
#define TYPES_H

#include "../acpi/actypes.h"
#include "../uapi/asm_generic/posix_types.h"

typedef unsigned long long u64;

struct hlist_node {
    struct hlist_node *next, **pprev;
};

typedef struct {
    long counter;
} atomic_long_t;

typedef __kernel_uid32_t uid_t;
typedef __kernel_gid32_t gid_t;

typedef unsigned short umode_t;

typedef u32 __kernel_dev_t;
typedef __kernel_dev_t dev_t;

struct list_head {
    struct list_head *next, *prev;
};

typedef struct {
    int counter;
} atomic_t;

#endif //TYPES_H
