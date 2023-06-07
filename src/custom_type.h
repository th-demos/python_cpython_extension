//
// Created by hwf on 2023/6/7.
//

#ifndef PYTON_CPYTHON_EXTENSION_SRC_CUSTOM_TYPE_H_
#define PYTON_CPYTHON_EXTENSION_SRC_CUSTOM_TYPE_H_
#include <Python.h>
extern PyTypeObject CustomType;

typedef struct {
  PyObject_HEAD
  /* Type-specific fields go here. */
  int someIntValue;
} CustomObject;
#endif //PYTON_CPYTHON_EXTENSION_SRC_CUSTOM_TYPE_H_
