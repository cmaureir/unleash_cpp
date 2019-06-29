#include <pybind11/pybind11.h>

std::string hello() {
   std::string msg = "Hello Python Users Berlin!";
   return msg;
}

PYBIND11_MODULE(simple, m) {
    m.def("hello", &hello, "A function that print a message");
}
