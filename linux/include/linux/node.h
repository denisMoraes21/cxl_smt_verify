//
// Created by denis on 03/11/24.
//

#ifndef NODE_H
#define NODE_H

struct access_coordinate {
    unsigned int read_bandwidth;
    unsigned int write_bandwidth;
    unsigned int read_latency;
    unsigned int write_latency;
};

enum access_coordinate_class {
    ACCESS_COORDINATE_LOCAL,
    ACCESS_COORDINATE_CPU,
    ACCESS_COORDINATE_MAX
};

#endif //NODE_H
