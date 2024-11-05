//
// Created by denis on 28/10/24.
//

#ifndef CXLMEM_H
#define CXLMEM_H

#include "../../include/linux/device.h"
#include "../../include/linux/cdev.h"
#include "../../include/linux/workqueue_types.h"
#include "../../include/asm-generic/int-ll64.h"
#include "../../include/linux/workqueue.h"
#include "../../include/linux/range.h"
#include "../../include/linux/node.h"

#define CXL_FW_STATE_BITS		32

enum poison_cmd_enabled_bits {
    CXL_POISON_ENABLED_LIST,
    CXL_POISON_ENABLED_INJECT,
    CXL_POISON_ENABLED_CLEAR,
    CXL_POISON_ENABLED_SCAN_CAPS,
    CXL_POISON_ENABLED_SCAN_MEDIA,
    CXL_POISON_ENABLED_SCAN_RESULTS,
    CXL_POISON_ENABLED_MAX
};

enum security_cmd_enabled_bits {
    CXL_SEC_ENABLED_SANITIZE,
    CXL_SEC_ENABLED_SECURE_ERASE,
    CXL_SEC_ENABLED_GET_SECURITY_STATE,
    CXL_SEC_ENABLED_SET_PASSPHRASE,
    CXL_SEC_ENABLED_DISABLE_PASSPHRASE,
    CXL_SEC_ENABLED_UNLOCK,
    CXL_SEC_ENABLED_FREEZE_SECURITY,
    CXL_SEC_ENABLED_PASSPHRASE_SECURE_ERASE,
    CXL_SEC_ENABLED_MAX
};

struct clx_memdev { // NOLINT(*-pro-type-member-init)
    struct device dev;
    struct cdev cdev;
    struct cxl_dev_state *cxlds{};
    struct work_struct detach_work;
    struct cxl_nvdimm_bridge *cxl_nvb{};
    struct cxl_port *endpoint{};
    int id;
    int depth;
};

struct cxl_mbox_cmd { // NOLINT(*-pro-type-member-init)
    u16 opcode;
    void *payload_in;
    void *payload_out;
    size_t size_in;
    size_t size_out;
    size_t min_out;
    int poll_count;
    int poll_interval_ms;
    u16 return_code;
};

struct cxl_event_state {
    struct cxl_get_event_payload *buf;
    struct mutex log_lock;
};

struct cxl_poison_state {
    u32 max_errors;
    DECLARE_BITMAP(enabled_cmds, CXL_POISON_ENABLED_MAX); // ?
    struct cxl_mbox_poison_out *list_out;
    struct mutex lock;
};

struct cxl_fw_state {
    DECLARE_BITMAP(state, CXL_FW_STATE_BITS); // ?
    bool oneshot;
    int num_slots;
    int cur_slot;
    int next_slot;
};

struct cxl_security_state {
    unsigned long state;
    DECLARE_BITMAP(enabled_cmds, CXL_SEC_ENABLED_MAX); // ?
    int poll_tmo_secs;
    bool sanitize_active;
    struct delayed_work poll_dwork;
    struct kernfs_node *sanitize_node;
};

struct cxl_dpa_perf {
    struct range dpa_range;
    struct access_coordinate coord[ACCESS_COORDINATE_MAX];
    struct access_coordinate cdat_coord[ACCESS_COORDINATE_MAX];
    int qos_class;
};

struct cxl_dev_state {
    struct device *dev;
    struct cxl_memdev *cxlmd;
    struct cxl_register_map reg_map;
    struct cxl_regs regs;
    int cxl_dvsec;
    bool rcd;
    bool media_ready;
    struct resource dpa_res;
    struct resource pmem_res;
    struct resource ram_res;
    u64 serial;
    enum cxl_devtype type;
    struct cxl_mailbox cxl_mbox;
};

struct cxl_memdev_state {
    struct cxl_dev_state cxlds;
    size_t lsa_size;
    char firmware_version[0x10];
    DECLARE_BITMAP(enabled_cmds, CXL_MEM_COMMAND_ID_MAX);
    DECLARE_BITMAP(exclusive_cmds, CXL_MEM_COMMAND_ID_MAX);
    u64 total_bytes;
    u64 volatile_only_bytes;
    u64 persistent_only_bytes;
    u64 partition_align_bytes;
    u64 active_volatile_bytes;
    u64 active_persistent_bytes;
    u64 next_volatile_bytes;
    u64 next_persistent_bytes;

    struct cxl_dpa_perf ram_perf;
    struct cxl_dpa_perf pmem_perf;

    struct cxl_event_state event;
    struct cxl_poison_state poison;
    struct cxl_security_state security;
    struct cxl_fw_state fw;
};

struct cxl_mem_command {
    struct cxl_command_info info;
    enum cxl_opcode opcode;
    u32 flags;
#define CXL_CMD_FLAG_FORCE_ENABLE BIT(0)
};

struct cxl_hdm {
    struct cxl_component_regs regs;
    unsigned int decoder_count;
    unsigned int target_count;
    unsigned int interleave_mask;
    unsigned long iw_cap_mask;
    struct cxl_port *port;
};

struct cxl_command_info {
    __u32 id;

    __u32 flags;
#define CXL_MEM_COMMAND_FLAG_MASK		GENMASK(1, 0)
#define CXL_MEM_COMMAND_FLAG_ENABLED		BIT(0)
#define CXL_MEM_COMMAND_FLAG_EXCLUSIVE		BIT(1)

    __u32 size_in;
    __u32 size_out;
};

struct cxl_mem_query_commands {
    __u32 n_commands;
    __u32 rsvd;
    struct cxl_command_info __user commands[]; /* out: supported commands */
};

#endif //CXLMEM_H
