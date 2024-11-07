//
// Created by denis on 07/11/24.
//

#ifndef NOTIFIER_H
#define NOTIFIER_H

typedef	int (*notifier_fn_t)(struct notifier_block *nb,
            unsigned long action, void *data);

struct notifier_block {
    notifier_fn_t notifier_call;
    struct notifier_block __rcu *next;
    int priority;
};

#endif //NOTIFIER_H
