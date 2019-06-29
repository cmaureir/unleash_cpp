from ctypes import CDLL, c_char_p

module = CDLL('./simple.so')
module.hello.restype = c_char_p
print(module.hello())
