all:
	cc linalg.c -c -o linalg.o -I. -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	ar rvs liblinalg.a *.o
clean:
	rm liblinalg.a *.o
install:
	cp *.h /usr/include
	cp liblinalg.a /usr/lib/

gcw0:
	mipsel-gcw0-linux-uclibc-cc linalg.c -c -o linalg.o -I. -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	mipsel-gcw0-linux-uclibc-ar rvs liblinalg.a *.o
install_gcw0:
	cp *.h /opt/gcw0-toolchain/usr/mipsel-gcw0-linux-uclibc/sysroot/usr/include
	cp liblinalg.a /opt/gcw0-toolchain/usr/mipsel-gcw0-linux-uclibc/sysroot/usr/lib
