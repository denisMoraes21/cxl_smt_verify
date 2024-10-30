#ifndef LINUX_DEVICE_H
#define LINUX_DEVICE_H

#include "kobject.h"
#include "mutex.h"

#define DEVICE_NAME "cxl_device"

typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned int dev_t;

struct device {
    struct kobject kobj;
    struct device *parent;
    struct device_private *p;
    const char *init_name = DEVICE_NAME;
    const struct device_type *type;
    const struct bus_type *bus;
    struct device_driver *driver;
    void *platform_data;
    void *driver_data;
    struct mutex mutex;
    struct dev_links_info links;
    struct dev_pm_info power;
    struct dev_pm_domain *pm_domain;
    // No CONFIG_ENERGY_MODEL
    // No CONFIG_PINCTRL
    struct dev_msi_info msi;
    // No CONFIG_ARCH_HAS_DMA_OPS
    u64 *dma_mask;
    u64 coherent_dma_mask;
    u64 bus_dma_limit;
    const struct bus_dma_region *dma_region;
    struct device_dma_parameters *dma_params;
    struct list_head dma_pools;
    // No CONFIG_DMA_DECLARE_COHERENT
    // No CONFIG_DMA_CMA
    // No CONFIG_SWIOTLB
    // No CONFIG_SWIOTLB_DYNAMIC
    struct dev_archdata archdata;
    struct device_node *of_node;
    struct fwnode_handle *fwnode;
    // No CONFIG_NUMA
    dev_t devt;
    u32 id;
    spinlock_t		devres_lock;
    struct list_head	devres_head;

    const struct class	*class;
    const struct attribute_group **groups;	/* optional groups */

    void	(*release)(struct device *dev);
    struct iommu_group	*iommu_group;
    struct dev_iommu	*iommu;

    struct device_physical_location *physical_location;

    enum device_removable	removable;

    bool			offline_disabled:1;
    bool			offline:1;
    bool			of_node_reused:1;
    bool			state_synced:1;
    bool			can_match:1;
    // No CONFIG_ARCH_HAS_SYNC_DMA_FOR_DEVICE
    // No CONFIG_DMA_OPS_BYPASS
    // No CONFIG_DMA_NEED_SYNC
    // No CONFIG_IOMMU_DMA
};

#endif