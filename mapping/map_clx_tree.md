# Structs
- struct cxl_memdev dev: https://github.com/torvalds/linux/blob/master/drivers/cxl/cxlmem.h#L49
  - struct device: https://github.com/torvalds/linux/blob/master/include/linux/device.h#L721
    - struct kobject: https://github.com/torvalds/linux/blob/master/include/linux/kobject.h#L64
      - const char *name;
      - struct list_head entry: https://github.com/torvalds/linux/blob/master/include/linux/types.h#L193
        - struct list_head *next, *prev;
      - struct kobject *parent;
      - struct kset	*kset;
      - const struct kobj_type *ktype;
      - struct kernfs_node *sd: 
      - struct kref	kref: https://github.com/torvalds/linux/blob/master/include/linux/kref.h#L19
      - unsigned int state_initialized:1;
      - unsigned int state_in_sysfs:1;
      - unsigned int state_add_uevent_sent:1;
      - unsigned int state_remove_uevent_sent:1;
      - unsigned int uevent_suppress:1;
        
            #ifdef CONFIG_DEBUG_KOBJECT_RELEASE
                struct delayed_work	release;
            #endif
    - struct device *parent
    - struct device_private	*p:
    - const char *init_name:
    - const struct device_type *type:
    - const struct bus_type	*bus: 
    - struct device_driver *driver:
    - void *platform_data:
    - void *driver_data:
    - struct mutex mutex:
    - struct dev_links_info	links: https://github.com/torvalds/linux/blob/master/include/linux/device.h#L531
      - struct list_head suppliers;
      - struct list_head consumers;
      - struct list_head defer_sync;
      - enum dl_dev_state status: https://github.com/torvalds/linux/blob/master/include/linux/device.h#L501
    - struct dev_pm_info power: https://github.com/torvalds/linux/blob/master/include/linux/pm.h#L663
      - pm_message_t power_state: https://github.com/torvalds/linux/blob/master/include/linux/pm.h#L60
      - bool can_wakeup:1;
      - bool async_suspend:1;
      - bool in_dpm_list:1;
      - bool is_prepared:1;
      - bool is_suspended:1;
      - bool is_noirq_suspended:1;
      - bool is_late_suspended:1;
      - bool no_pm:1;
      - bool early_init:1;
      - bool direct_complete:1;
      - u32	driver_flags: https://github.com/torvalds/linux/blob/master/include/acpi/actypes.h#L120
      - spinlock_t lock: https://github.com/torvalds/linux/blob/master/include/linux/spinlock_types.h#L29
        - struct raw_spinlock rlock: https://github.com/torvalds/linux/blob/master/include/linux/spinlock_types_raw.h#L14
          - arch_spinlock_t raw_lock: https://github.com/torvalds/linux/blob/master/include/linux/spinlock_types_up.h#L25
          
                  #ifdef CONFIG_DEBUG_SPINLOCK
                      unsigned int magic, owner_cpu;
                      void *owner;
                  #endif
                  #ifdef CONFIG_DEBUG_LOCK_ALLOC
                      struct lockdep_map dep_map;
                  #endif
          
                #ifdef CONFIG_DEBUG_LOCK_ALLOC
                # define LOCK_PADSIZE (offsetof(struct raw_spinlock, dep_map))
                struct {
                u8 __padding[LOCK_PADSIZE];
                struct lockdep_map dep_map;
                };
                #endif
      
                #ifdef CONFIG_PM_SLEEP
                struct list_head entry;
                struct completion completion;
                struct wakeup_source *wakeup;
                bool wakeup_path:1;
                bool syscore:1;
                bool no_pm_callbacks:1;
                bool async_in_progress:1;
                bool must_resume:1;
                bool may_skip_resume:1;
                #else
      - bool should_wakeup:1;
      
            #endif
            #ifdef CONFIG_PM
                struct hrtimer suspend_timer;
                u64	timer_expires;
                struct work_struct work;
                wait_queue_head_t wait_queue;
                struct wake_irq	*wakeirq;
                atomic_t usage_count;
                atomic_t child_count;
                unsigned int disable_depth:3;
                bool idle_notification:1;
                bool request_pending:1;
                bool deferred_resume:1;
                bool needs_force_resume:1;
                bool runtime_auto:1;
                bool ignore_children:1;
                bool no_callbacks:1;
                bool irq_safe:1;
                bool use_autosuspend:1;
                bool timer_autosuspends:1;
                bool memalloc_noio:1;
                unsigned int links_count;
                enum rpm_request request;
                enum rpm_status	runtime_status;
                enum rpm_status	last_status;
                int	runtime_error;
                int	autosuspend_delay;
                u64	last_busy;
                u64	active_time;
                u64	suspended_time;
                u64	accounting_timestamp;
            #endif
      
      - struct pm_subsys_data	*subsys_data;
      - void (*set_latency_tolerance)(struct device *, s32):
      - struct dev_pm_qos	*qos;
    - struct dev_pm_domain *pm_domain:
    
          #ifdef CONFIG_ENERGY_MODEL 
          struct em_perf_domain	*em_pd;
          #endif
          #ifdef CONFIG_PINCTRL
          struct dev_pin_info	*pins;
          #endif
    - struct dev_msi_info msi: https://github.com/torvalds/linux/blob/master/include/linux/device.h#L721
    
          #ifdef CONFIG_ARCH_HAS_DMA_OPS
          const struct dma_map_ops *dma_ops;
          #endif
  
    - u64 *dma_mask;
    - u64 coherent_dma_mask;
    - u64 bus_dma_limit;
    - const struct bus_dma_region *dma_range_map;
    - struct device_dma_parameters *dma_params;
    - struct list_head	dma_pools;

          #ifdef CONFIG_DMA_DECLARE_COHERENT
          struct dma_coherent_mem	*dma_mem;
          #endif
          #ifdef CONFIG_DMA_CMA
          struct cma *cma_area;
          #endif
          #ifdef CONFIG_SWIOTLB
          struct io_tlb_mem *dma_io_tlb_mem;
          #endif
          #ifdef CONFIG_SWIOTLB_DYNAMIC
          struct list_head dma_io_tlb_pools;
          spinlock_t dma_io_tlb_lock;
          bool dma_uses_io_tlb;
          #endif
    
    - struct dev_archdata archdata: https://github.com/torvalds/linux/blob/master/include/asm-generic/device.h#L8
	- struct device_node *of_node;
	- struct fwnode_handle *fwnode;

          #ifdef CONFIG_NUMA
          int numa_node;	
          #endif
    
    - dev_t	devt;
    - u32 id;
    - spinlock_t devres_lock;
	- struct list_head devres_head;
    - cost struct class	*class: https://github.com/torvalds/linux/blob/master/include/linux/device/class.h#L50
      - const char *name;
      - const struct attribute_group **class_groups;
      - const struct attribute_group **dev_groups;
      - int (*dev_uevent)(const struct device *dev, struct kobj_uevent_env *env);
      - char *(*devnode)(const struct device *dev, umode_t *mode): https://github.com/torvalds/linux/blob/master/include/linux/types.h#L24
      - void (*class_release)(const struct class *class);
      - void (*dev_release)(struct device *dev);
      - int (*shutdown_pre)(struct device *dev);
      - const struct kobj_ns_type_operations *ns_type;
      - const void *(*namespace)(const struct device *dev);
      - void (*get_ownership)(const struct device *dev, kuid_t *uid, kgid_t *gid): https://github.com/torvalds/linux/blob/master/include/linux/uidgid_types.h#L9
      - const struct dev_pm_ops *pm;
	- const struct attribute_group **groups;
	- void (*release)(struct device *dev);
	- struct iommu_group *iommu_group;
	- struct dev_iommu *iommu;
	- struct device_physical_location *physical_location;
	- enum device_removable	removable: https://github.com/torvalds/linux/blob/master/include/linux/device.h#L517
	- bool offline_disabled:1;
	- bool offline:1;
	- bool of_node_reused:1;
	- bool state_synced:1;
	- bool can_match:1;
    
          #if defined(CONFIG_ARCH_HAS_SYNC_DMA_FOR_DEVICE) || \
          defined(CONFIG_ARCH_HAS_SYNC_DMA_FOR_CPU) || \
          defined(CONFIG_ARCH_HAS_SYNC_DMA_FOR_CPU_ALL)
          bool			dma_coherent:1;
          #endif
          #ifdef CONFIG_DMA_OPS_BYPASS
          bool			dma_ops_bypass : 1;
          #endif
          #ifdef CONFIG_DMA_NEED_SYNC
          bool			dma_skip_sync:1;
          #endif
          #ifdef CONFIG_IOMMU_DMA
          bool			dma_iommu:1;
          #endif
  - struct cdev cdev: https://github.com/torvalds/linux/blob/master/include/linux/cdev.h#L14
    - struct kobject kobj;
    - struct module *owner;
    - const struct file_operations *ops;
    - struct list_head list;
    - dev_t dev;
    - unsigned int count;
  - struct cxl_dev_state *cxlds;
  - struct work_struct detach_work:
    - atomic_long_t data: https://github.com/torvalds/linux/blob/master/tools/include/linux/types.h#L83
    - struct list_head entry;
    - work_func_t func;
    
          #ifdef CONFIG_LOCKDEP
          struct lockdep_map lockdep_map;
          #endif
  - struct cxl_nvdimm_bridge *cxl_nvb;
  - struct cxl_nvdimm *cxl_nvd;
  - struct cxl_port *endpoint;
  - int id;
  - int depth;