#build the modules
import os
from distutils.core import setup, Extension

os.environ["CC"] = "g++"
os.environ["CFLAGS"] = "-std=c++17"

setup(name='myglob', version='1.0',
      ext_modules=[Extension('myglob', ['myglob.cpp'])])
