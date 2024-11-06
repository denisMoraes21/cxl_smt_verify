//
// Created by denis on 05/11/24.
//

#ifndef CXL_MEM_H
#define CXL_MEM_H

#include "types.h"

struct cxl_mem_query_commands { // NOLINT(*-pro-type-member-init)
    __u32 n_commands;
    __u32 rsvd;
    struct cxl_command_info __user commands[];
};

struct cxl_send_command {
    __u32 id;
    __u32 flags;
    union {
        struct {
            __u16 opcode;
            __u16 rsvd;
        } raw;
        __u32 rsvd;
    };
    __u32 retval;

    struct {
        __u32 size;
        __u32 rsvd;
        __u64 payload;
    } in;

    struct {
        __u32 size;
        __u32 rsvd;
        __u64 payload;
    } out;
};

#endif //CXL_MEM_H
