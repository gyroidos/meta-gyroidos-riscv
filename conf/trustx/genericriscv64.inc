MACHINE = "qemuriscv64"

INITRAMFS_IMAGE_BUNDLE = "1"
INITRAMFS_IMAGE = "trustx-cml-initramfs"

IMAGE_FSTYPES = "cpio ext4"
TRUSTME_FSTYPES = "wic wic.bmap"
TRUSTME_PARTTABLE_TYPE = "gpt"
TRUSTME_CONTAINER_ARCH = "qemuriscv64"

TRUSTME_HARDWARE = "x86"
TRUSTME_LOGTTY = "tty11"

#WCAST_ALIGN = "n"

PKI_UEFI_KEYS = "y"

PACKAGE_CLASSES = "package_ipk"
BBMULTICONFIG = "container"

PREFERRED_PROVIDER_virtual/kernel:qemuriscv64 ?= "linux-rolling-stable"
PREFERRED_PROVIDER_virtual/kernel:gyroidos-cml ?= "linux-rolling-stable"

INITRAMFS_MODULES = ""

INITRAMFS_MAXSIZE = "150000"

PACKAGE_INSTALL:append:pn-trustx-cml-initramfs = "${INITRAMFS_MODULES}"
PACKAGE_INSTALL:append:pn-trustx-installer-initramfs = "${INITRAMFS_MODULES}"

KERNEL_IMAGETYPE = "Image"
KERNEL_IMAGETYPES:remove = "uImage"
EXTRA_IMAGEDEPENDS:remove = "opensbi"

IMAGE_BOOT_FILES:genericx86-64 = "${KERNEL_DEPLOYSUBDIR}/Image-initramfs-${MACHINE}.bin;EFI/BOOT/BOOTX64.EFI"
WKS_FILE:genericx86-64 = "trustx-cml.genericx86.wks.in"
