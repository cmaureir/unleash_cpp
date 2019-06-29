#include <Python.h>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

static PyObject* myglob_glob(PyObject* self, PyObject* args){
    const char *directory;
    if (!PyArg_ParseTuple(args, "s", &directory))
        return NULL;

    //std::vector<std::string> v;
    PyObject *l = PyList_New(0);

    //for (const auto &entry : fs::directory_iterator(path))
    for (const auto &entry : fs::recursive_directory_iterator(directory)) {
        PyList_Append(l, PyUnicode_FromString(entry.path().c_str()));
    }
        //v.push_back(entry.path());

    //std::cout << v.size() << std::endl;
    return l;
}

static char myglob_docs[] =
    "hello(): print hello message\n";

static PyMethodDef myglob_funcs[] = {
    {"glob", (PyCFunction)myglob_glob, METH_VARARGS, myglob_docs},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef myglobmodule = {
    PyModuleDef_HEAD_INIT,
    "myglob",
    myglob_docs,
    -1,
    myglob_funcs
};

PyMODINIT_FUNC PyInit_myglob(void){
    return PyModule_Create(&myglobmodule);
}
