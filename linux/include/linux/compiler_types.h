//
// Created by denis on 05/11/24.
//

#ifndef COMPILER_TYPES_H
#define COMPILER_TYPES_H

# define __rcu __attribute__((noderef, address_space(__rcu))) // NOLINT(*-reserved-identifier)

#endif //COMPILER_TYPES_H
