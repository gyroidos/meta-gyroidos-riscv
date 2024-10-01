FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += "file://${MACHINE}.cfg"

KBUILD_DEFCONFIG:qemuriscv64 = "defconfig"
#KERNEL_FEATURES:remove = "cfg/fs/vfat.scc"

KERNEL_FEATURES:remove = "features/debug/printk.scc"
KERNEL_FEATURES:remove = "features/kernel-sample/kernel-sample.scc"
