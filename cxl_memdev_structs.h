#ifndef CXL_STRUCTS_H
#define CXL_STRUCTS_H

// driver core device object
struct device {
};

// char dev core object for ioctl operations
struct cdev {

};

// the device state backing this device
struct cxl_dev_state {

};

// active memdev lost a port in its ancestry
struct work_struct {

};

// coordinate removal of cxl_nvd if present
struct cxl_nvdimm_bridge {

};

// optional bridge to a nvdimm if the device supports pmem
struct cxl_nvdimm {

};

// connection to the CXL port topology for this memory device
struct cxl_port {

};

#endif //CXL_STRUCTS_H
