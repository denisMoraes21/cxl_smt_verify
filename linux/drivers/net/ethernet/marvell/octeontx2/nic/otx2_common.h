//
// Created by denis on 06/11/24.
//

#ifndef OTX2_COMMON_H
#define OTX2_COMMON_H

#include "../af/mbox.h"
#include "../../../../../../include/linux/workqueue_types.h"
#include "../../../../../../include/linux/mutex_types.h"

struct mbox {
    struct otx2_mbox	mbox_;
    struct work_struct	mbox_wrk;
    struct otx2_mbox	mbox_up;
    struct work_struct	mbox_up_wrk;
    struct otx2_nic		*pfvf;
    void			*bbuf_base;
    struct mutex		lock;
    int			num_msgs;
    int			up_num_msgs;
};

#endif //OTX2_COMMON_H
