from cffi import FFI

ffibuilder = FFI()
ffibuilder.set_source("_simple","""
char* hello() {
   char *msg = "Hello Euro Python 2019!";
   return msg;
}
    """)

ffibuilder.cdef("""
    char* hello();
    """)


if __name__ == "__main__":
    ffibuilder.compile(verbose=True)
