//
// Created by denis on 06/11/24.
//

#ifndef STDDEF_H
#define STDDEF_H

#define struct_group_tagged(TAG, NAME, MEMBERS...) \
__struct_group(TAG, NAME, /* no attrs */, MEMBERS)

#endif //STDDEF_H
