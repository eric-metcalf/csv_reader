#
# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.

cmake_minimum_required (VERSION 2.8.11)

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually
# cause another cmake executable to run. The same process will walk through
# the project's entire directory structure.


include_directories(include)
include_directories(src)
include_directories(test)


# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
#target_link_libraries (helloDemo LINK_PUBLIC Hello)

# CMakeLists files in this project can # refer to the root source director

add_library(test_csv_reader test/csv_reader_test.cpp)
add_library(csv_reader src/csv_reader.cpp)


add_executable (helloDemo test/csv_reader_test.cpp src/csv_reader.cpp)

target_include_directories (test_csv_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

project (CSV_Reader)


# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
#target_link_libraries (helloDemo LINK_PUBLIC Hello)