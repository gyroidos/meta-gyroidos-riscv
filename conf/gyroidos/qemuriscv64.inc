MACHINE = "qemuriscv64"

INITRAMFS_IMAGE_BUNDLE = "1"
INITRAMFS_IMAGE = "gyroidos-cml-initramfs"

IMAGE_FSTYPES = "cpio ext4"
GYROIDOS_FSTYPES = "wic wic.bmap"
GYROIDOS_PARTTABLE_TYPE = "gpt"
GYROIDOS_CONTAINER_ARCH = "qemuriscv64"
GYROIDOS_LOGTTY = "tty11"

#WCAST_ALIGN = "n"

PKI_UEFI_KEYS = "y"

PACKAGE_CLASSES = "package_ipk"
BBMULTICONFIG = "container"

PREFERRED_PROVIDER_virtual/kernel:qemuriscv64 ?= "linux-rolling-stable"
PREFERRED_PROVIDER_virtual/kernel:cml-base ?= "linux-rolling-stable"

INITRAMFS_MODULES = ""

INITRAMFS_MAXSIZE = "150000"

PACKAGE_INSTALL:append:pn-gyroidos-cml-initramfs = "${INITRAMFS_MODULES}"

KERNEL_IMAGETYPE = "Image"
KERNEL_IMAGETYPES:remove = "uImage"
EXTRA_IMAGEDEPENDS:remove = "opensbi"

IMAGE_BOOT_FILES:qemuriscv64 = "${KERNEL_DEPLOYSUBDIR}/Image-initramfs-${MACHINE}.bin;EFI/BOOT/BOOTRISCV64.EFI"
WKS_FILE:qemuriscv64 = "gyroidos-cml.${MACHINE}.wks.in"
