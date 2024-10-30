# Functions
int __cxl_pci_mbox_send_cmd(struct cxl_mailbox *cxl_mbox, struct cxl_mbox_cmd *mbox_cmd)
void set_exclusive_cxl_commands(struct cxl_memdev_state *mds, unsigned long *cmds)
void clear_exclusive_cxl_commands(struct cxl_memdev_state *mds, unsigned long *cmds)
int cxl_mem_get_fw_info(struct cxl_memdev_state *mds)
int cxl_mem_activate_fw(struct cxl_memdev_state *mds, int slot)
int cxl_mem_abort_fw_xfer(struct cxl_memdev_state *mds)
struct cxl_register_map
struct cxl_hdm *devm_cxl_setup_hdm(struct cxl_port *port, struct cxl_endpoint_dvsec_info *info)
int devm_cxl_enumerate_decoders(struct cxl_hdm *cxlhdm, struct cxl_endpoint_dvsec_info *info)
void cxl_coordinates_combine(struct access_coordinate *out, struct access_coordinate *c1, struct access_coordinate *c2)
int cxl_endpoint_gather_bandwidth(struct cxl_region *cxlr, struct cxl_endpoint_decoder *cxled, struct xarray *usp_xa, bool *gp_is_root)
struct xarray *cxl_switch_gather_bandwidth(struct cxl_region *cxlr, struct xarray *input_xa, bool *gp_is_root)
struct xarray *cxl_hb_gather_bandwidth(struct xarray *xa)¶
struct xarray *cxl_rp_gather_bandwidth(struct xarray *xa)
void cxl_region_update_bandwidth(struct cxl_region *cxlr, struct xarray *input_xa)
void cxl_region_shared_upstream_bandwidth_update(struct cxl_region *cxlr)¶
struct cxl_port *devm_cxl_add_port(struct device *host, struct device *uport_dev, resource_size_t component_reg_phys, struct cxl_dport *parent_dport)¶
struct cxl_dport *devm_cxl_add_dport(struct cxl_port *port, struct device *dport_dev, int port_id, resource_size_t component_reg_phys)
struct cxl_dport *devm_cxl_add_rch_dport(struct cxl_port *port, struct device *dport_dev, int port_id, resource_size_t rcrb)
int cxl_add_ep(struct cxl_dport *dport, struct device *ep_dev)
int cxl_decoder_init(struct cxl_port *port, struct cxl_decoder *cxld)
struct cxl_root_decoder *cxl_root_decoder_alloc(struct cxl_port *port, unsigned int nr_targets)
struct cxl_switch_decoder *cxl_switch_decoder_alloc(struct cxl_port *port, unsigned int nr_targets)¶
struct cxl_endpoint_decoder *cxl_endpoint_decoder_alloc(struct cxl_port *port)
int cxl_decoder_add_locked(struct cxl_decoder *cxld, int *target_map)¶
int cxl_decoder_add(struct cxl_decoder *cxld, int *target_map)
int __cxl_driver_register(struct cxl_driver *cxl_drv, struct module *owner, const char *modname)
int cxl_endpoint_get_perf_coordinates(struct cxl_port *port, struct access_coordinate *coord)
int devm_cxl_port_enumerate_dports(struct cxl_port *port)
int cxl_hdm_decode_init(struct cxl_dev_state *cxlds, struct cxl_hdm *cxlhdm, struct cxl_endpoint_dvsec_info *info)
void read_cdat_data(struct cxl_port *port)
void cxl_dport_init_ras_reporting(struct cxl_dport *dport, struct device *host)
long cxl_pci_get_latency(struct pci_dev *pdev)
int cxl_port_attach_region(struct cxl_port *port, struct cxl_region *cxlr, struct cxl_endpoint_decoder *cxled, int pos)
int cxl_calc_interleave_pos(struct cxl_endpoint_decoder *cxled)¶
struct cxl_region *devm_cxl_add_region(struct cxl_root_decoder *cxlrd, int id, enum cxl_decoder_mode mode, enum cxl_decoder_type type)
int devm_cxl_add_pmem_region(struct cxl_region *cxlr)

# Structs
struct cxl_memdev
struct cxl_mbox_cmd
struct cxl_event_state
struct cxl_poison_state
struct cxl_fw_state
struct cxl_security_state
struct cxl_dpa_perf
struct cxl_dev_state
struct cxl_memdev_state
struct cxl_mem_command
struct cxl_hdm
struct cxl_decoder
struct cxl_endpoint_decoder
struct cxl_switch_decoder
struct cxl_root_decoder
struct cxl_region_params
struct cxl_region
struct cxl_port
struct cxl_root
struct cxl_dport
struct cxl_ep
struct cxl_region_ref
struct cxl_endpoint_dvsec_info
struct cxl_command_info
struct cxl_mem_query_commands
struct cxl_send_command
