//
// Created by hwf on 2023/6/7.
//

#include "./custom_type.h"
#include <Python.h>

static PyObject* Custom_new(PyTypeObject *type, PyObject *arg, PyObject *kwargs) {
  auto *self = reinterpret_cast<CustomObject *>(type->tp_alloc(type, 0));
  printf("Custom_new called\n");
  return reinterpret_cast<PyObject *>(self);
}

PyTypeObject CustomType = {
    PyVarObject_HEAD_INIT(nullptr, 0)
    "custom.Custom",
    sizeof(CustomObject),
    0,
    nullptr,
    0,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    0,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    0,
    nullptr,
    nullptr,
    Custom_new,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
