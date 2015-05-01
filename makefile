all:
	cc src/ml.c -c -o src/ml.o -I./include -Wall -Werror -pedantic -std=c11 -ffast-math -g -O2 -lc -lm -D_GNU_SOURCE
	ar rvs libml.a src/*.o
clean:
	rm libml.a src/*.o
install:
	cp include/*.h /usr/include
	cp libml.a /usr/lib/
