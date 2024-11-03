#ifndef LINUX_DEVICE_H
#define LINUX_DEVICE_H

#include "kobject.h"
#include "mutex.h"
#include "pm.h"
#include "../asm-generic/device.h"
#include "types.h"
#include "device/class.h"

enum device_removable {
	DEVICE_REMOVABLE_NOT_SUPPORTED = 0,
	DEVICE_REMOVABLE_UNKNOWN,
	DEVICE_FIXED,
	DEVICE_REMOVABLE,
};

typedef unsigned long long u64;

struct dev_msi_info {
// #ifdef CONFIG_GENERIC_MSI_IRQ
// 	struct irq_domain	*domain;
// 	struct msi_device_data	*data;
// #endif
};


enum dl_dev_state {
	DL_DEV_NO_DRIVER = 0,
	DL_DEV_PROBING,
	DL_DEV_DRIVER_BOUND,
	DL_DEV_UNBINDING,
};

struct dev_links_info {
	struct list_head suppliers;
	struct list_head consumers;
	struct list_head defer_sync;
	enum dl_dev_state status;
};

struct device {
	struct kobject kobj;
	struct device *parent;
	struct device_private *p;
	const char		*init_name;
	const struct device_type *type;
	const struct bus_type	*bus;
	struct device_driver *driver;
	void *platform_data;
	void *driver_data;
	struct mutex mutex;
	struct dev_links_info links;
	struct dev_pm_info	power;
	struct dev_pm_domain	*pm_domain;
// #ifdef CONFIG_ENERGY_MODEL
// 	struct em_perf_domain	*em_pd;
// #endif
// #ifdef CONFIG_PINCTRL
// 	struct dev_pin_info	*pins;
// #endif
	struct dev_msi_info	msi;
// #ifdef CONFIG_ARCH_HAS_DMA_OPS
// 	const struct dma_map_ops *dma_ops;
// #endif
	u64	*dma_mask;
	u64	coherent_dma_mask;
	u64	bus_dma_limit;
	const struct bus_dma_region *dma_range_map;
	struct device_dma_parameters *dma_params;
	struct list_head dma_pools;
// #ifdef CONFIG_DMA_DECLARE_COHERENT
// 	struct dma_coherent_mem	*dma_mem;
// #endif
// #ifdef CONFIG_DMA_CMA
// 	struct cma *cma_area;
// #endif
// #ifdef CONFIG_SWIOTLB
// 	struct io_tlb_mem *dma_io_tlb_mem;
// #endif
// #ifdef CONFIG_SWIOTLB_DYNAMIC
// 	struct list_head dma_io_tlb_pools;
// 	spinlock_t dma_io_tlb_lock;
// 	bool dma_uses_io_tlb;
// #endif
	struct dev_archdata	archdata;
	struct device_node *of_node;
	struct fwnode_handle *fwnode;
// #ifdef CONFIG_NUMA
// 	int		numa_node;
// #endif
	dev_t devt;
	u32	id;
	spinlock_t devres_lock;
	struct list_head devres_head;
	const struct class_ *class_;
	const struct attribute_group **groups;
	void (*release)(struct device *dev);
	struct iommu_group	*iommu_group;
	struct dev_iommu	*iommu;
	struct device_physical_location *physical_location;
	enum device_removable removable;
	bool offline_disabled:1;
	bool offline:1;
	bool of_node_reused:1;
	bool state_synced:1;
	bool can_match:1;
// #if defined(CONFIG_ARCH_HAS_SYNC_DMA_FOR_DEVICE) || \
//     defined(CONFIG_ARCH_HAS_SYNC_DMA_FOR_CPU) || \
//     defined(CONFIG_ARCH_HAS_SYNC_DMA_FOR_CPU_ALL)
// 	bool			dma_coherent:1;
// #endif
// #ifdef CONFIG_DMA_OPS_BYPASS
// 	bool			dma_ops_bypass : 1;
// #endif
// #ifdef CONFIG_DMA_NEED_SYNC
// 	bool			dma_skip_sync:1;
// #endif
// #ifdef CONFIG_IOMMU_DMA
// 	bool			dma_iommu:1;
// #endif
};

#endif