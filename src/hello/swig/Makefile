all:
	swig -python example.i
	gcc -fPIC -c example.c example_wrap.c -I/usr/include/python3.7m
	ld  -shared example.o example_wrap.o -o _example.so
