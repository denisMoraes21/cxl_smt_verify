//
// Created by denis on 06/11/24.
//

#ifndef MBOX_H
#define MBOX_H

struct otx2_mbox {
    struct pci_dev *pdev;
    void   *hwbase;
    void   *reg_base;
    u64    trigger;
    u16    tr_shift;
    u64    rx_start;
    u64    tx_start;
    u16    rx_size;
    u16    tx_size;
    u16    ndevs;
    struct otx2_mbox_dev *dev;
};

#endif //MBOX_H
