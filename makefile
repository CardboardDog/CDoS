all:
	make -f make_b
clean:
	make -f make_b clean
test:
	make -f make_b
	qemu-system-x86_64 dist/CDOS.iso