# this is the build file for project 
# it is autogenerated by the xmake build system.
# do not edit by hand.

CCACHE=/usr/bin/ccache
RC=/usr/bin/rustc
CU=/opt/cuda/bin/nvcc
AS=/usr/bin/gcc
MM=/usr/bin/gcc
GC=/usr/bin/go
CXX=/usr/bin/gcc
MXX=/usr/bin/gcc
CC=/usr/bin/gcc

RCLD=/usr/bin/rustc
LD=/usr/bin/g++
GCLD=/usr/bin/go
RCAR=/usr/bin/rustc
AR=/usr/bin/ar
GCAR=/usr/bin/go
RCSH=/usr/bin/rustc
SH=/usr/bin/g++
CULD=/opt/cuda/bin/nvcc

main_CXXFLAGS=-m64 -fvisibility=hidden -fvisibility-inlines-hidden -Wall -Werror -O3 -std=c++17 -Iinclude -I/usr/local/include -I/usr/include -fno-strict-aliasing -fPIC -fvisibility=hidden -fno-trapping-math -Ofast -DNDEBUG
main_CXXFLAGS=-m64 -fvisibility=hidden -fvisibility-inlines-hidden -Wall -Werror -O3 -std=c++17 -Iinclude -I/usr/local/include -I/usr/include -fno-strict-aliasing -fPIC -fvisibility=hidden -fno-trapping-math -Ofast -DNDEBUG
main_LDFLAGS=-m64 -Lbuild/linux/x86_64/release -s -llibdaa -lgtest
daa_CXXFLAGS=-m64 -Wall -Werror -O3 -std=c++17 -Iinclude -I/usr/local/include -I/usr/include -isystem /home/pablo/.xmake/packages/p/pybind11/v2.10.0/41ef60b323db424f8cf3967e35d79f9e/include -isystem /usr/include/python3.10 -fno-strict-aliasing -fPIC -fvisibility=hidden -fno-trapping-math -Ofast -DNDEBUG
daa_CXXFLAGS=-m64 -Wall -Werror -O3 -std=c++17 -Iinclude -I/usr/local/include -I/usr/include -isystem /home/pablo/.xmake/packages/p/pybind11/v2.10.0/41ef60b323db424f8cf3967e35d79f9e/include -isystem /usr/include/python3.10 -fno-strict-aliasing -fPIC -fvisibility=hidden -fno-trapping-math -Ofast -DNDEBUG
daa_SHFLAGS=-shared -fPIC -m64 -L/usr/lib -Lbuild/linux/x86_64/release -s -lpython3.10 -lssl -lcrypto -lffi -lz -llibdaa
test_CXXFLAGS=-m64 -fvisibility=hidden -fvisibility-inlines-hidden -Wall -Werror -O3 -std=c++17 -Iinclude -I/usr/local/include -I/usr/include -DGTEST_HAS_PTHREAD=1 -isystem /home/pablo/.xmake/packages/g/gtest/1.12.1/77b9096bc4b34d9282f672d36b015ba9/include -fno-strict-aliasing -fPIC -fvisibility=hidden -fno-trapping-math -Ofast -DNDEBUG
test_CXXFLAGS=-m64 -fvisibility=hidden -fvisibility-inlines-hidden -Wall -Werror -O3 -std=c++17 -Iinclude -I/usr/local/include -I/usr/include -DGTEST_HAS_PTHREAD=1 -isystem /home/pablo/.xmake/packages/g/gtest/1.12.1/77b9096bc4b34d9282f672d36b015ba9/include -fno-strict-aliasing -fPIC -fvisibility=hidden -fno-trapping-math -Ofast -DNDEBUG
test_LDFLAGS=-m64 -L/home/pablo/.xmake/packages/g/gtest/1.12.1/77b9096bc4b34d9282f672d36b015ba9/lib -L/usr/lib -Lbuild/linux/x86_64/release -s -lgtest_main -lgmock -llibdaa -lpthread -lgtest
libdaa_CXXFLAGS=-m64 -fvisibility=hidden -fvisibility-inlines-hidden -Wall -Werror -O3 -std=c++17 -Iinclude -I/usr/local/include -I/usr/include -fno-strict-aliasing -fPIC -fvisibility=hidden -fno-trapping-math -Ofast -DNDEBUG
libdaa_CXXFLAGS=-m64 -fvisibility=hidden -fvisibility-inlines-hidden -Wall -Werror -O3 -std=c++17 -Iinclude -I/usr/local/include -I/usr/include -fno-strict-aliasing -fPIC -fvisibility=hidden -fno-trapping-math -Ofast -DNDEBUG
libdaa_ARFLAGS=-cr

default:  main daa test libdaa

all:  main daa test libdaa

.PHONY: default all  main daa test libdaa

main: build/linux/x86_64/release/main
build/linux/x86_64/release/main: build/linux/x86_64/release/liblibdaa.a build/.objs/main/linux/x86_64/release/src/main.cpp.o
	@echo linking.release main
	@mkdir -p build/linux/x86_64/release
	@$(LD) -o build/linux/x86_64/release/main build/.objs/main/linux/x86_64/release/src/main.cpp.o $(main_LDFLAGS) > build/.build.log 2>&1

build/.objs/main/linux/x86_64/release/src/main.cpp.o: src/main.cpp
	@echo ccache compiling.release src/main.cpp
	@mkdir -p build/.objs/main/linux/x86_64/release/src
	@$(CXX) -c $(main_CXXFLAGS) -o build/.objs/main/linux/x86_64/release/src/main.cpp.o src/main.cpp > build/.build.log 2>&1

daa: build/linux/x86_64/release/daa.so
build/linux/x86_64/release/daa.so: build/linux/x86_64/release/liblibdaa.a build/.objs/daa/linux/x86_64/release/src/daa/sorting/quicksort.cpp.o
	@echo linking.release daa.so
	@mkdir -p build/linux/x86_64/release
	@$(SH) -o build/linux/x86_64/release/daa.so build/.objs/daa/linux/x86_64/release/src/daa/sorting/quicksort.cpp.o $(daa_SHFLAGS) > build/.build.log 2>&1

build/.objs/daa/linux/x86_64/release/src/daa/sorting/quicksort.cpp.o: src/daa/sorting/quicksort.cpp
	@echo ccache compiling.release src/daa/sorting/quicksort.cpp
	@mkdir -p build/.objs/daa/linux/x86_64/release/src/daa/sorting
	@$(CXX) -c $(daa_CXXFLAGS) -o build/.objs/daa/linux/x86_64/release/src/daa/sorting/quicksort.cpp.o src/daa/sorting/quicksort.cpp > build/.build.log 2>&1

test: build/linux/x86_64/release/test
build/linux/x86_64/release/test: build/linux/x86_64/release/liblibdaa.a build/.objs/test/linux/x86_64/release/test/sorting/quicksort/shuffled/quicksort_shuffled_tests.cpp.o build/.objs/test/linux/x86_64/release/test/sorting/quicksort/ordered/quicksort_ordered_tests.cpp.o build/.objs/test/linux/x86_64/release/test/sorting/quicksort/reverse_ordered/quicksort_reverse_ordered_tests.cpp.o build/.objs/test/linux/x86_64/release/test/main.cpp.o
	@echo linking.release test
	@mkdir -p build/linux/x86_64/release
	@$(LD) -o build/linux/x86_64/release/test build/.objs/test/linux/x86_64/release/test/sorting/quicksort/shuffled/quicksort_shuffled_tests.cpp.o build/.objs/test/linux/x86_64/release/test/sorting/quicksort/ordered/quicksort_ordered_tests.cpp.o build/.objs/test/linux/x86_64/release/test/sorting/quicksort/reverse_ordered/quicksort_reverse_ordered_tests.cpp.o build/.objs/test/linux/x86_64/release/test/main.cpp.o $(test_LDFLAGS) > build/.build.log 2>&1

build/.objs/test/linux/x86_64/release/test/sorting/quicksort/shuffled/quicksort_shuffled_tests.cpp.o: test/sorting/quicksort/shuffled/quicksort_shuffled_tests.cpp
	@echo ccache compiling.release test/sorting/quicksort/shuffled/quicksort_shuffled_tests.cpp
	@mkdir -p build/.objs/test/linux/x86_64/release/test/sorting/quicksort/shuffled
	@$(CXX) -c $(test_CXXFLAGS) -o build/.objs/test/linux/x86_64/release/test/sorting/quicksort/shuffled/quicksort_shuffled_tests.cpp.o test/sorting/quicksort/shuffled/quicksort_shuffled_tests.cpp > build/.build.log 2>&1

build/.objs/test/linux/x86_64/release/test/sorting/quicksort/ordered/quicksort_ordered_tests.cpp.o: test/sorting/quicksort/ordered/quicksort_ordered_tests.cpp
	@echo ccache compiling.release test/sorting/quicksort/ordered/quicksort_ordered_tests.cpp
	@mkdir -p build/.objs/test/linux/x86_64/release/test/sorting/quicksort/ordered
	@$(CXX) -c $(test_CXXFLAGS) -o build/.objs/test/linux/x86_64/release/test/sorting/quicksort/ordered/quicksort_ordered_tests.cpp.o test/sorting/quicksort/ordered/quicksort_ordered_tests.cpp > build/.build.log 2>&1

build/.objs/test/linux/x86_64/release/test/sorting/quicksort/reverse_ordered/quicksort_reverse_ordered_tests.cpp.o: test/sorting/quicksort/reverse_ordered/quicksort_reverse_ordered_tests.cpp
	@echo ccache compiling.release test/sorting/quicksort/reverse_ordered/quicksort_reverse_ordered_tests.cpp
	@mkdir -p build/.objs/test/linux/x86_64/release/test/sorting/quicksort/reverse_ordered
	@$(CXX) -c $(test_CXXFLAGS) -o build/.objs/test/linux/x86_64/release/test/sorting/quicksort/reverse_ordered/quicksort_reverse_ordered_tests.cpp.o test/sorting/quicksort/reverse_ordered/quicksort_reverse_ordered_tests.cpp > build/.build.log 2>&1

build/.objs/test/linux/x86_64/release/test/main.cpp.o: test/main.cpp
	@echo ccache compiling.release test/main.cpp
	@mkdir -p build/.objs/test/linux/x86_64/release/test
	@$(CXX) -c $(test_CXXFLAGS) -o build/.objs/test/linux/x86_64/release/test/main.cpp.o test/main.cpp > build/.build.log 2>&1

libdaa: build/linux/x86_64/release/liblibdaa.a
build/linux/x86_64/release/liblibdaa.a: build/.objs/libdaa/linux/x86_64/release/src/libdaa/sorting/quicksort.cpp.o
	@echo linking.release liblibdaa.a
	@mkdir -p build/linux/x86_64/release
	@$(AR) $(libdaa_ARFLAGS) build/linux/x86_64/release/liblibdaa.a build/.objs/libdaa/linux/x86_64/release/src/libdaa/sorting/quicksort.cpp.o > build/.build.log 2>&1

build/.objs/libdaa/linux/x86_64/release/src/libdaa/sorting/quicksort.cpp.o: src/libdaa/sorting/quicksort.cpp
	@echo ccache compiling.release src/libdaa/sorting/quicksort.cpp
	@mkdir -p build/.objs/libdaa/linux/x86_64/release/src/libdaa/sorting
	@$(CXX) -c $(libdaa_CXXFLAGS) -o build/.objs/libdaa/linux/x86_64/release/src/libdaa/sorting/quicksort.cpp.o src/libdaa/sorting/quicksort.cpp > build/.build.log 2>&1

clean:  clean_main clean_daa clean_test clean_libdaa

clean_main:  clean_libdaa
	@rm -rf build/linux/x86_64/release/main
	@rm -rf build/linux/x86_64/release/main.sym
	@rm -rf build/.objs/main/linux/x86_64/release/src/main.cpp.o

clean_daa:  clean_libdaa
	@rm -rf build/linux/x86_64/release/daa.so
	@rm -rf build/linux/x86_64/release/daa.sym
	@rm -rf build/.objs/daa/linux/x86_64/release/src/daa/sorting/quicksort.cpp.o

clean_test:  clean_libdaa
	@rm -rf build/linux/x86_64/release/test
	@rm -rf build/linux/x86_64/release/test.sym
	@rm -rf build/.objs/test/linux/x86_64/release/test/sorting/quicksort/shuffled/quicksort_shuffled_tests.cpp.o
	@rm -rf build/.objs/test/linux/x86_64/release/test/sorting/quicksort/ordered/quicksort_ordered_tests.cpp.o
	@rm -rf build/.objs/test/linux/x86_64/release/test/sorting/quicksort/reverse_ordered/quicksort_reverse_ordered_tests.cpp.o
	@rm -rf build/.objs/test/linux/x86_64/release/test/main.cpp.o

clean_libdaa: 
	@rm -rf build/linux/x86_64/release/liblibdaa.a
	@rm -rf build/linux/x86_64/release/libdaa.sym
	@rm -rf build/.objs/libdaa/linux/x86_64/release/src/libdaa/sorting/quicksort.cpp.o

