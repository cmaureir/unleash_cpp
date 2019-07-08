python configure.py
g++ -c simple.cpp
ar -crs  libsimple.a simple.o
#sudo cp libsimple.a /usr/lib/
make
make install
