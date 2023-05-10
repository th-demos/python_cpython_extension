import setuptools


setuptools.setup(
    name='foo',
    ext_modules=[setuptools.Extension("foo", ["src/foomodule.cc"])]
)
