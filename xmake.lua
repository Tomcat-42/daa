set_languages("c++20")
add_rules("mode.debug", "mode.release")

-- NOTE: Change later to a more automated config
add_includedirs("include", "/usr/local/include", "/usr/include")

add_cxflags("-fno-strict-aliasing", "-fPIC", "-fvisibility=hidden", "-fno-trapping-math", "-Ofast")

set_optimize("fastest")
set_policy("check.auto_ignore_flags", false)

add_rules("plugin.compile_commands.autoupdate")

-- set_optimize("agressive")

local lib_deps = {}
local python_lib_deps = { "pybind11" }
local test_deps = { "gtest" }

add_requires("pybind11", "gtest")

-- main C++ library to be used with the Python bindings
target("daa")
set_kind("static")
-- set_targetdir(".")
add_files("src/daa/**/*.cpp")
-- set_default(false)
add_packages(table.unpack(lib_deps))
set_installdir("/usr/local")
set_targetdir("./daa")

-- python bindings library
target("pydaa")
set_kind("shared")
set_prefixname("")
-- set_targetdir(".")
add_packages(table.unpack(python_lib_deps))
-- set_default(true)
add_files("src/pydaa/**/*.cpp", "src/pydaa/pydaa.cpp")
add_deps("daa")
set_installdir("/usr/local")
set_targetdir("./daa")

-- test target
target("daa_test")
set_kind("binary")
add_files("test/**/*.cpp", "test/main.cpp")
add_ldflags("-lgtest")
-- set_default(false)
add_packages(table.unpack(test_deps))
add_deps("daa")
set_installdir("/usr/local")
set_targetdir("./daa")

-- standalone
target("main")
set_kind("binary")
-- set_default(false)
add_files("src/main.cpp")
add_deps("daa")
