#build the modules

from distutils.core import setup, Extension

setup(name='simple', version='1.0',
      ext_modules=[Extension('simple', ['simple.c'])])
