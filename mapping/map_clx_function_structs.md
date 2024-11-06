# Functions
1. int __cxl_pci_mbox_send_cmd(struct cxl_mailbox *cxl_mbox, struct cxl_mbox_cmd *mbox_cmd)
2. void set_exclusive_cxl_commands(struct cxl_memdev_state *mds, unsigned long *cmds)
3. void clear_exclusive_cxl_commands(struct cxl_memdev_state *mds, unsigned long *cmds)
4. int cxl_mem_get_fw_info(struct cxl_memdev_state *mds)
5. int cxl_mem_activate_fw(struct cxl_memdev_state *mds, int slot)
6. int cxl_mem_abort_fw_xfer(struct cxl_memdev_state *mds)
7. struct cxl_register_map
8. struct cxl_hdm *devm_cxl_setup_hdm(struct cxl_port *port, struct cxl_endpoint_dvsec_info *info)
9. int devm_cxl_enumerate_decoders(struct cxl_hdm *cxlhdm, struct cxl_endpoint_dvsec_info *info)
10. void cxl_coordinates_combine(struct access_coordinate *out, struct access_coordinate *c1, struct access_coordinate *c2)
11. int cxl_endpoint_gather_bandwidth(struct cxl_region *cxlr, struct cxl_endpoint_decoder *cxled, struct xarray *usp_xa, bool *gp_is_root)
12. struct xarray *cxl_switch_gather_bandwidth(struct cxl_region *cxlr, struct xarray *input_xa, bool *gp_is_root)
13. struct xarray *cxl_hb_gather_bandwidth(struct xarray *xa)
14. struct xarray *cxl_rp_gather_bandwidth(struct xarray *xa)
15. void cxl_region_update_bandwidth(struct cxl_region *cxlr, struct xarray *input_xa)
16. void cxl_region_shared_upstream_bandwidth_update(struct cxl_region *cxlr)¶
17. struct cxl_port *devm_cxl_add_port(struct device *host, struct device *uport_dev, resource_size_t component_reg_phys, struct cxl_dport *parent_dport)
18. struct cxl_dport *devm_cxl_add_dport(struct cxl_port *port, struct device *dport_dev, int port_id, resource_size_t component_reg_phys)
19. struct cxl_dport *devm_cxl_add_rch_dport(struct cxl_port *port, struct device *dport_dev, int port_id, resource_size_t rcrb)
20. int cxl_add_ep(struct cxl_dport *dport, struct device *ep_dev)
21. int cxl_decoder_init(struct cxl_port *port, struct cxl_decoder *cxld)
22. struct cxl_root_decoder *cxl_root_decoder_alloc(struct cxl_port *port, unsigned int nr_targets)
23. struct cxl_switch_decoder *cxl_switch_decoder_alloc(struct cxl_port *port, unsigned int nr_targets)¶
24. struct cxl_endpoint_decoder *cxl_endpoint_decoder_alloc(struct cxl_port *port)
25. int cxl_decoder_add_locked(struct cxl_decoder *cxld, int *target_map)¶
26. int cxl_decoder_add(struct cxl_decoder *cxld, int *target_map)
27. int __cxl_driver_register(struct cxl_driver *cxl_drv, struct module *owner, const char *modname)
28. int cxl_endpoint_get_perf_coordinates(struct cxl_port *port, struct access_coordinate *coord)
29. int devm_cxl_port_enumerate_dports(struct cxl_port *port)
30. int cxl_hdm_decode_init(struct cxl_dev_state *cxlds, struct cxl_hdm *cxlhdm, struct cxl_endpoint_dvsec_info *info)
31. void read_cdat_data(struct cxl_port *port)
32. void cxl_dport_init_ras_reporting(struct cxl_dport *dport, struct device *host)
33. long cxl_pci_get_latency(struct pci_dev *pdev)
34. int cxl_port_attach_region(struct cxl_port *port, struct cxl_region *cxlr, struct cxl_endpoint_decoder *cxled, int pos)
35. int cxl_calc_interleave_pos(struct cxl_endpoint_decoder *cxled)¶
36. struct cxl_region *devm_cxl_add_region(struct cxl_root_decoder *cxlrd, int id, enum cxl_decoder_mode mode, enum cxl_decoder_type type)
37. int devm_cxl_add_pmem_region(struct cxl_region *cxlr)

# Structs
1. struct cxl_memdev - ok
2. struct cxl_mbox_cmd - ok
3. struct cxl_event_state - ok
4. struct cxl_poison_state - ?
5. struct cxl_fw_state - ?
6. struct cxl_security_state - ?
7. struct cxl_dpa_perf - ok
8. struct cxl_dev_state - 
9. struct cxl_memdev_state - 
10. struct cxl_mem_command - 
11. struct cxl_hdm -
12. struct cxl_decoder - ?
13. struct cxl_endpoint_decoder - 
14. struct cxl_switch_decoder - 
15. struct cxl_root_decoder - 
16. struct cxl_region_params - 
17. struct cxl_region - 
18. struct cxl_port - 
19. struct cxl_root - ok 
20. struct cxl_dport - 
21. struct cxl_ep - ok
22. struct cxl_region_ref - ok
23. struct cxl_endpoint_dvsec_info - ok
24. struct cxl_command_info - ok
25. struct cxl_mem_query_commands - ok
26. struct cxl_send_command - ok
