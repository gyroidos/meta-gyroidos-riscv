MACHINE = "beaglev-fire"

PREFERRED_PROVIDER_virtual/kernel:beaglev-fire ?= "mpfs-linux"
PREFERRED_PROVIDER_virtual/kernel:cml-base ?= "mpfs-linux"

INITRAMFS_IMAGE_BUNDLE = "0"
INITRAMFS_IMAGE = "gyroidos-cml-initramfs"

GYROIDOS_PARTTABLE_TYPE = "gpt"
GYROIDOS_HARDWARE = "riscv"
GYROIDOS_LOGTTY = "ttyS0"
GYROIDOS_CONTAINER_ARCH = "qemuriscv64"
GYROIDOS_FSTYPES = "wic wic.bmap"

GYROIDOS_TARGET_ALIGN = "4096"

UBOOT_ENV = "boot"
UBOOT_ENV_SUFFIX = "scr"
UBOOT_ENV_SIZE = "0x2000"

IMAGE_INSTALL:remove = " dt-overlay-mchp"
HSS_PAYLOAD = "uboot"

#WCAST_ALIGN = "n"

PKI_UEFI_KEYS = "n"

PACKAGE_CLASSES = "package_ipk"
BBMULTICONFIG = "container"

INITRAMFS_MODULES = ""

INITRAMFS_MAXSIZE = "150000"

PACKAGE_INSTALL:append:pn-gyroidos-cml-initramfs = "${INITRAMFS_MODULES}"

KERNEL_CLASSES:append = " kernel-fitimage "
KERNEL_IMAGETYPE:beaglev-fire = "fitImage"

IMAGE_BOOT_FILES:beaglev-fire = " \
    ${KERNEL_DEPLOYSUBDIR}/fitImage-gyroidos-cml-initramfs-${MACHINE}-${MACHINE};fitImage \
    boot.scr \
    uboot.env \
    u-boot.bin \
"

WKS_FILE:beaglev-fire = "gyroidos-cml.mpfs.wks.in"

SERIAL_CONSOLES = "115200;ttyS0 115200;ttyS1"
