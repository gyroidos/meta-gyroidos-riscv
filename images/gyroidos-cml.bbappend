KERNEL_IMAGE_FILE = "cml-kernel/Image-initramfs-${MACHINE}.bin"
KERNEL_IMAGE_FILE:beaglev-fire = "cml-kernel/fitImage-gyroidos-cml-initramfs-${MACHINE}-${MACHINE}"

OS_CONFIG_IN := "${THISDIR}/${PN}/${OS_NAME}.conf"
OS_CONFIG_IN:beaglev-fire := "${THISDIR}/${PN}/${OS_NAME}-${MACHINE}.conf"

do_sign_guestos:prepend:beaglev-fire () {
        mkdir -p "${UPDATE_OUT}"
        for i in boot.scr u-boot.bin uboot.env; do
                cp ${DEPLOY_DIR_IMAGE}/$i ${UPDATE_OUT}/$i.img
        done
}
