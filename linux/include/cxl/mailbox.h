//
// Created by denis on 07/11/24.
//

#ifndef MAILBOX_H
#define MAILBOX_H

#include "../linux/mutex_types.h"
#include "../linux/rcuwait.h"

struct cxl_mailbox { // NOLINT(*-pro-type-member-init)
    struct device *host;
    size_t payload_size;
    struct mutex mbox_mutex; /* lock to protect mailbox context */
    struct rcuwait mbox_wait;
    int (*mbox_send)(struct cxl_mailbox *cxl_mbox, struct cxl_mbox_cmd *cmd);
};

#endif //MAILBOX_H
