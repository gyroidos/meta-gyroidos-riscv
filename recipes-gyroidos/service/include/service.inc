# disable warnings for cast align on RISC-V builds
WCAST_ALIGN_qemuriscv64 = "n"
EXTRA_OEMAKE += "WCAST_ALIGN=${WCAST_ALIGN}"

