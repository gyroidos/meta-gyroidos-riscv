require efitools-common.inc

SRC_URI[md5sum] = "5f20ed9cccf786cf6525c54537ae7831"
SRC_URI[sha256sum] = "d48b66768374ce742971c44e475b7336992b3d0a51407920a2e3876e8d9fc329"

inherit native
inherit perlnative

DEPENDS = "gnu-efi-native help2man-native sbsigntool-native libfile-slurp-perl-native"

EFIFILES = "\
	LockDown.efi \
	KeyTool.efi \
"

BINARIES = "\
	cert-to-efi-sig-list \
	sig-list-to-certs \
	sign-efi-sig-list \
	hash-to-efi-sig-list \
	cert-to-efi-hash-list \
"

LIBRARY_FLAGS = "\
	-nostdlib -shared -Bsymbolic \
	${STAGING_LIBDIR}/crt0-efi-${HOST_ARCH}.o \
	-L ${STAGING_LIBDIR} \
	-T ${STAGING_LIBDIR}/elf_${HOST_ARCH}_efi.lds \
"

#tmp/sysroots-components/x86_64/gnu-efi-native/usr/lib/crt0-efi-x86_64.o

INCLUDES = "\
	-I${S}/include \
	-I${STAGING_INCDIR} \
	-I${STAGING_INCDIR}/efi \
	-I${STAGING_INCDIR}/efi/${HOST_ARCH} \
	-I${STAGING_INCDIR}/efi/protocol \
"

# overwrite compiler and compiler flags in makefile
EXTRA_OEMAKE = "\
        'CC = ${CC} -L ${STAGING_LIBDIR}' \
        'LD = ${LD}' \
	'INCDIR = ${INCLUDES}' \
	'LDFLAGS = ${LIBRARY_FLAGS}' \
"

do_compile() {
	oe_runmake ${BINARIES}
	oe_runmake ${EFIFILES}
}

do_install () {
	install -d ${D}${bindir}
	for bin in ${BINARIES} ${EFIFILES}; do
		install ${S}/${bin} ${D}${bindir}
	done
}
