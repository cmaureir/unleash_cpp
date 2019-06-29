#include <Python.h>

static PyObject* simple_hello(PyObject* self, PyObject* args){
    char *msg = "Hello Python Pizza Berlin!";
    return Py_BuildValue("s", msg);
}

static char simple_docs[] =
    "hello(): print hello message\n";

static PyMethodDef simple_funcs[] = {
    {"hello", (PyCFunction)simple_hello, METH_NOARGS, simple_docs},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef simplemodule = {
    PyModuleDef_HEAD_INIT,
    "simple",
    simple_docs,
    -1,
    simple_funcs
};

PyMODINIT_FUNC PyInit_simple(void){
    return PyModule_Create(&simplemodule);
}
