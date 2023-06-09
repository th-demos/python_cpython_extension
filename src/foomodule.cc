//
// Created by hwf on 2023/5/10.
//

#include <Python.h>
#include "./custom_type.h"

static PyObject *
custom_module_hello(PyObject *self, PyObject *args) {
  CustomObject *obj = PyObject_NEW(CustomObject , &CustomType);
  obj->ob_base.ob_refcnt;
  printf("custom object: %p\n", obj);
  printf("refer count: %lld\n", obj->ob_base.ob_refcnt);
  return Py_None;
}

static PyMethodDef custom_module_methods[] = {
    {"hello", custom_module_hello, METH_VARARGS,
     "hello in foo module"},
    {nullptr, nullptr, 0, nullptr}        /* Sentinel */
};

static struct PyModuleDef customModule = {
    PyModuleDef_HEAD_INIT,
    "custom",   /* name of module */
    "custom module", /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    custom_module_methods
};


PyMODINIT_FUNC
PyInit_custom(void) {
  PyObject *m;
  if (PyType_Ready(&CustomType) < 0)
    return nullptr;

  m = PyModule_Create(&customModule);

  if (PyModule_AddObject(m, "Custom", (PyObject *) &CustomType) < 0) {
    printf("look like add Custom Type failed!\n");
    Py_DECREF(&CustomType);
    Py_DECREF(m);
    return nullptr;
  }
  if (m == nullptr)
    return nullptr;
  return m;
}