//
// Created by denis on 07/11/24.
//

static const struct memdev {
    const char *name;
    const struct file_operations *fops;
    fmode_t fmode;
    umode_t mode;
} devlist[] = {
//#ifdef CONFIG_DEVMEM
//    [DEVMEM_MINOR] = { "mem", &mem_fops, 0, 0 },
//#endif
    [3] = { "null", &null_fops, FMODE_NOWAIT, 0666 },
//#ifdef CONFIG_DEVPORT
//    [4] = { "port", &port_fops, 0, 0 },
//#endif
    [5] = { "zero", &zero_fops, FMODE_NOWAIT, 0666 },
    [7] = { "full", &full_fops, 0, 0666 },
    [8] = { "random", &random_fops, FMODE_NOWAIT, 0666 },
    [9] = { "urandom", &urandom_fops, FMODE_NOWAIT, 0666 },
//#ifdef CONFIG_PRINTK
//    [11] = { "kmsg", &kmsg_fops, 0, 0644 },
//#endif
};
