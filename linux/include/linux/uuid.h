//
// Created by denis on 07/11/24.
//

#ifndef UUID_H
#define UUID_H

#include "types.h"

#define UUID_SIZE 16

typedef struct {
    __u8 b[UUID_SIZE];
} uuid_t;

#endif //UUID_H
