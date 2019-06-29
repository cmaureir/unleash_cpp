all:
	c++ -O3 -Wall -shared -std=c++11 -fPIC `/usr/bin/python -m pybind11 --includes` example.cpp -o simple`python-config --extension-suffix`
