require recipes-kernel/linux/linux-gyroidos.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:beaglev-fire = " file://beaglev-fire-serial.cfg"
