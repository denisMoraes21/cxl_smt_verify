//
// Created by denis on 07/11/24.
//

#ifndef IOPORT_H
#define IOPORT_H

struct resource {
    resource_size_t start;
    resource_size_t end;
    const char *name;
    unsigned long flags;
    unsigned long desc;
    struct resource *parent, *sibling, *child;
};

#endif //IOPORT_H
