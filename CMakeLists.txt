# 这里的cmake list只是用来让clion认识工程结构，并不实际去编译
cmake_minimum_required(VERSION 3.16)
project(pyton_cpython_extension)

add_library(foomodule src/foomodule.cc)

find_package(Python REQUIRED COMPONENTS Development)

target_link_libraries(foomodule Python::Python)