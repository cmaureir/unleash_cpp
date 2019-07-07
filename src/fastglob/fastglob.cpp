#include <Python.h>
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

static PyObject* fastglob_glob(PyObject* self, PyObject* args, PyObject* kwds){

    const char *kwlist[] = {"directory", "recursive",0};
    const char *directory = nullptr;
    const int *recursive = nullptr;

    if (!PyArg_ParseTupleAndKeywords(args, kwds,
                                     "z|p",
                                     const_cast<char **>(kwlist),
                                     &directory,
                                     &recursive))
        return nullptr;

    PyObject *l = PyList_New(0);

    if (recursive)
    {
        for (const auto &entry : fs::recursive_directory_iterator(directory))
            PyList_Append(l, PyUnicode_FromString(entry.path().c_str()));
    }
    else
    {
        for (const auto &entry : fs::directory_iterator(directory))
            PyList_Append(l, PyUnicode_FromString(entry.path().c_str()));
    }

    return l;
}

static char fastglob_docs[] =
    "glob(path, recursive=False): super fast glob\n";

static PyMethodDef fastglob_funcs[] = {
    {"glob", (PyCFunction)fastglob_glob, METH_VARARGS|METH_KEYWORDS, 0},
    {nullptr, nullptr, 0, nullptr}
};

static struct PyModuleDef fastglobmodule = {
    PyModuleDef_HEAD_INIT,
    "fastglob",
    fastglob_docs,
    -1,
    fastglob_funcs
};

PyMODINIT_FUNC PyInit_fastglob(void){
    return PyModule_Create(&fastglobmodule);
}
