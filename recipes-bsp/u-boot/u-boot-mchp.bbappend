FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

COMPATIBLE_MACHINE:beaglev-fire = "beaglev-fire"

SRC_URI:append:beaglev-fire = "file://${UBOOT_ENV}.cmd"
