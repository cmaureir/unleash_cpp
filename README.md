# EuroPython 2019 :snake: :ch:
## Unleash the power of C++ in Python

*"A guide through the bindings generation process"*

This repository has all the content of the talk
from the conference.

### Examples

The examples contain a simple implementation of a `Hello World`
written in C and C++, then a basic implementation using different tools
is used to expose the function to Python.

* `cpython`, using a simple raw CPython implementation for the function.
* `ctypes`, to load the shared library (not used in the talk).
* [Boost::python](https://www.boost.org/doc/libs/1_61_0/libs/python/doc/html/index.html)
* [SWIG](http://www.swig.org/)
* [shiboken](https://doc.qt.io/qtforpython/shiboken2/)
* [pyBind11](https://pybind11.readthedocs.io)
* [cffi](https://cffi.readthedocs.io">cffi.readthedocs.io)
* [cppyy](https://cppyy.readthedocs.io)
* [sip](https://riverbankcomputing.com/software/sip)

A more useful example related to `glob` is included too in the directory
*fastglob*. This example uses the `<filesystem>` C++ library to achieve
a similar result as `glob` and `Pathlib.glob`.

* `fastglob`, directory with the implementation of the module.
* `data`, 1000 directories with 1000 empty files each.
* `glob_list.py`, listing using `glob`.
* `pathlib_list.py`, listing using `Pathlib`.
* `fastglob_list.py`, listing using `fastglob`.
* `benchmark_1.sh`, benchmark using `/usr/bin/time`.
* `benchmark_2.py`, benchmark using `time`.

### Slides

The slides are written using `reveal.js`.

