all:
	cc src/ml.c -c -o src/ml.o -I./include -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	ar rvs libml.a src/*.o
clean:
	rm libml.a src/*.o
install:
	cp include/*.h /usr/include
	cp libml.a /usr/lib/

gcw0:
	mipsel-gcw0-linux-uclibc-cc src/ml.c -c -o src/ml.o -I./include -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	ar rvs libml.a src/*.o
install-gcw0:
	cp include/*.h /opt/gcw0-toolchain/usr/mipsel-gcw0-linux-uclibc/sysroot/usr/include
	cp libml.a /opt/gcw0-toolchain/usr/mipsel-gcw0-linux-uclibc/sysroot/usr/lib
