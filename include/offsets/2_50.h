#ifndef OFFSETS_2_50_H
#define OFFSETS_2_50_H

uint64_t g_sym_map_250[] = {
    0x4CB3B50,          // KERNEL_SYM_DMPML4I
    0x4CB3B54,          // KERNEL_SYM_DMPDPI
    0x4CB38AC,          // KERNEL_SYM_PML4PML4I
    0x4CB38C8,          // KERNEL_SYM_PMAP_STORE
    0x7C40000,          // KERNEL_SYM_DATA_CAVE
    0x0,                // KERNEL_SYM_SCESBLAUTHMGRISLOADABLE2
    0x0,                // KERNEL_SYM_SCESBLAUTHMGRGETSELFINFO
    0x0,                // KERNEL_SYM_FPU_KERN_ENTER
    0x0,                // KERNEL_SYM_FPU_KERN_LEAVE
    0x0,                // KERNEL_SYM_FPU_KERN_CTX
    0x0,                // KERNEL_SYM_SHA256HMAC
    0x0,                // KERNEL_SYM_AESCBCCFB128DECRYPT
    0x0,                // KERNEL_SYM_MTX_LOCK_FLAGS
    0x0,                // KERNEL_SYM_MTX_UNLOCK_FLAGS
    0x0,                // KERNEL_SYM_SBL_DRV_MSG_MTX
    0x0,                // KERNEL_SYM_GPU_VA_PAGE_LIST
    0x0,                // KERNEL_SYM_SCESBLDRIVERSENDMSG
    0x0,                // KERNEL_SYM_SCESBLPFSSETKEYS
    0x0,                // KERNEL_SYM_RSAESPKCS1V15DEC2048CRT
    0x0,                // KERNEL_SYM_SX_XLOCK
    0x0,                // KERNEL_SYM_SX_XUNLOCK
    0x0,                // KERNEL_SYM_AESCBCCFB128ENCRYPT
    0x0,                // KERNEL_SYM_SCESBLKEYMGRSETKEYFORPFS
    0x0,                // KERNEL_SYM_SCESBLKEYMGRCLEARKEY
    0x0,                // KERNEL_SYM_SCESBLKEYMGRSMCALLFUNC
    0x0,                // KERNEL_SYM_SBL_KEYMGR_KEY_RBTREE
    0x0,                // KERNEL_SYM_SCESBLKEYMGRSETKEYSTORAGE
    0x0,                // KERNEL_SYM_SBL_KEYMGR_KEY_SLOTS
    0x0,                // KERNEL_SYM_SBL_KEYMGR_BUF_VA
    0x0,                // KERNEL_SYM_SBL_KEYMGR_BUF_GVA
};

uint64_t g_patch_map_250[] = {
    0x0580EB0,          // KERNEL_PATCH_HAS_MMAP_SELF_CAPABILITY
    0x0580EC0,          // KERNEL_PATCH_IS_ALLOWED_TO_MMAP_SELF
    0x09A6A59,          // KERNEL_PATCH_MMAP_SELF_CALL_IS_LOADABLE
    0x02A67D0,          // KERNEL_PATCH_SYS_GETGID
};

#endif // OFFSETS_2_50_H