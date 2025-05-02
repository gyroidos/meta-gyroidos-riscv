## Remove redirection of console output for beaglev-fire
do_install:prepend:beaglev-fire() {
	sed -i '/exec > \/dev\/$LOGTTY*/c\#exec > \/dev\/$LOGTTY' ${WORKDIR}/cml-boot-script.stub
	sed -i '/exec 2>&1*/c\#exec 2>&1' ${WORKDIR}/cml-boot-script.stub
}
