cmake_minimum_required(VERSION 3.23)
project(FileReader C)

set(CMAKE_C_STANDARD 17)

add_executable(FileReader main.c fileReader.c fileReader.h fileWriter.c fileWriter.h)

# set output target
set_target_properties(FileReader
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "/usr/lib/"
        LIBRARY_OUTPUT_DIRECTORY "/usr/lib/"
        RUNTIME_OUTPUT_DIRECTORY "/usr/bin/"
        )

# find the math library
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    # link target with math library
    target_link_libraries(FileReader PUBLIC ${MATH_LIBRARY})
endif()

# define header file path
target_include_directories(FileReader PRIVATE include)

# set to use C11 features
target_compile_features(FileReader PRIVATE c_std_17)

# set compiler options
target_compile_options(FileReader PRIVATE -Wall -O3)

# specify what to install when we run 'make install'
install(TARGETS FileReader DESTINATION bin)