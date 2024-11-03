//
// Created by denis on 03/11/24.
//

#ifndef PM_H
#define PM_H

#include "../acpi/actypes.h"
#include "spinlock_types.h"

typedef struct pm_message {
    int event;
} pm_message_t;

struct dev_pm_info {
    pm_message_t power_state;
    bool can_wakeup:1;
    bool async_suspend:1;
    bool in_dpm_list:1;
    bool is_prepared:1;
    bool is_suspended:1;
    bool is_noirq_suspended:1;
    bool is_late_suspended:1;
    bool no_pm:1;
    bool early_init:1;
    bool direct_complete:1;
    u32	driver_flags;
    spinlock_t lock;
//#ifdef CONFIG_PM_SLEEP
//    struct list_head	entry;
//    struct completion	completion;
//    struct wakeup_source	*wakeup;
//    bool			wakeup_path:1;
//    bool			syscore:1;
//    bool			no_pm_callbacks:1;
//    bool			async_in_progress:1;
//    bool			must_resume:1;
//    bool			may_skip_resume:1;
//#else
    bool should_wakeup:1;
//#endif
//#ifdef CONFIG_PM
//    struct hrtimer		suspend_timer;
//    u64			timer_expires;
//    struct work_struct	work;
//    wait_queue_head_t	wait_queue;
//    struct wake_irq		*wakeirq;
//    atomic_t		usage_count;
//    atomic_t		child_count;
//    unsigned int		disable_depth:3;
//    bool			idle_notification:1;
//    bool			request_pending:1;
//    bool			deferred_resume:1;
//    bool			needs_force_resume:1;
//    bool			runtime_auto:1;
//    bool			ignore_children:1;
//    bool			no_callbacks:1;
//    bool			irq_safe:1;
//    bool			use_autosuspend:1;
//    bool			timer_autosuspends:1;
//    bool			memalloc_noio:1;
//    unsigned int		links_count;
//    enum rpm_request	request;
//    enum rpm_status		runtime_status;
//    enum rpm_status		last_status;
//    int			runtime_error;
//    int			autosuspend_delay;
//    u64			last_busy;
//    u64			active_time;
//    u64			suspended_time;
//    u64			accounting_timestamp;
//#endif
    struct pm_subsys_data *subsys_data;
    void (*set_latency_tolerance)(struct device *, s32);
    struct dev_pm_qos	*qos;
};

#endif //PM_H
