//
// Created by hwf on 2023/5/10.
//

#include <Python.h>

static PyObject *
foo_hello(PyObject *self, PyObject *args) {
  printf("hello foo");
  return Py_None;
}

static PyMethodDef foo_methods[] = {
    {"hello",  foo_hello, METH_VARARGS,
          "hello in foo module"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef foomodule = {
    PyModuleDef_HEAD_INIT,
    "spam",   /* name of module */
    "foo module", /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    foo_methods
};


PyMODINIT_FUNC
PyInit_foo(void) {
  PyObject *m;
  m = PyModule_Create(&foomodule);
  if (m == nullptr)
    return nullptr;
  return m;
}