import setuptools


setuptools.setup(
    name='custom',
    ext_modules=[setuptools.Extension("custom", ["src/foomodule.cc", "src/custom_type.cc"])]
)
