file(GLOB_RECURSE SOURCE CONFIGURE_DEPENDS include/**/*.hpp src/pydaa/*.cpp
     src/daa/*.cpp)

pybind11_add_module(pydaa ${SOURCE} src/pydaa/*.cpp src/pydaa/**/*.cpp)

target_include_directories(pydaa PRIVATE include /usr/include /usr/local/include)
