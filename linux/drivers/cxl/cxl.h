//
// Created by denis on 03/11/24.
//

#ifndef CXL_H
#define CXL_H

struct cxl_register_map {
    struct device *host;
    void __iomem *base;
    resource_size_t resource;
    resource_size_t max_size;
    u8 reg_type;
    union {
        struct cxl_component_reg_map component_map;
        struct cxl_device_reg_map device_map;
        struct cxl_pmu_reg_map pmu_map;
    };
};

struct cxl_endpoint_decoder {
    struct cxl_decoder cxld;
    struct resource *dpa_res;
    resource_size_t skip;
    enum cxl_decoder_mode mode;
    enum cxl_decoder_state state;
    int pos;
};

struct cxl_switch_decoder {
    struct cxl_decoder cxld;
    int nr_targets;
    struct cxl_dport *target[];
};

struct cxl_root_decoder {
    struct resource *res;
    atomic_t region_id;
    cxl_hpa_to_spa_fn hpa_to_spa;
    void *platform_data;
    struct mutex range_lock;
    int qos_class;
    struct cxl_switch_decoder cxlsd;
};

struct cxl_region_params {
    enum cxl_config_state state;
    uuid_t uuid;
    int interleave_ways;
    int interleave_granularity;
    struct resource *res;
    struct cxl_endpoint_decoder *targets[CXL_DECODER_MAX_INTERLEAVE];
    int nr_targets;
};


struct cxl_region {
    struct device dev;
    int id;
    enum cxl_decoder_mode mode;
    enum cxl_decoder_type type;
    struct cxl_nvdimm_bridge *cxl_nvb;
    struct cxl_pmem_region *cxlr_pmem;
    unsigned long flags;
    struct cxl_region_params params;
    struct access_coordinate coord[ACCESS_COORDINATE_MAX];
    struct notifier_block memory_notifier;
    struct notifier_block adist_notifier;
};

struct cxl_port {
    struct device dev;
    struct device *uport_dev;
    struct device *host_bridge;
    int id;
    struct xarray dports;
    struct xarray endpoints;
    struct xarray regions;
    struct cxl_dport *parent_dport;
    struct ida decoder_ida;
    struct cxl_register_map reg_map;
    int nr_dports;
    int hdm_end;
    int commit_end;
    bool dead;
    unsigned int depth;
    struct cxl_cdat {
        void *table;
        size_t length;
    } cdat;
    bool cdat_available;
    long pci_latency;
};

struct cxl_root {
    struct cxl_port port;
    const struct cxl_root_ops *ops;
};

struct cxl_dport {
    struct device *dport_dev;
    struct cxl_register_map reg_map;
    int port_id;
    struct cxl_rcrb_info rcrb;
    bool rch;
    struct cxl_port *port;
    struct cxl_regs regs;
    struct access_coordinate coord[ACCESS_COORDINATE_MAX];
    long link_latency;
};

struct cxl_ep {
    struct device *ep;
    struct cxl_dport *dport;
    struct cxl_port *next;
};

struct cxl_region_ref {
    struct cxl_port *port;
    struct cxl_decoder *decoder;
    struct cxl_region *region;
    struct xarray endpoints;
    int nr_targets_set;
    int nr_eps;
    int nr_targets;
};

struct cxl_endpoint_dvsec_info {
    bool mem_enabled;
    int ranges;
    struct cxl_port *port;
    struct range dvsec_range[2];
};



#endif //CXL_H
