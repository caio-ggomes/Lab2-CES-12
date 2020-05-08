cmake_minimum_required(VERSION 3.10)

cmake_policy(SET CMP0048 NEW)
project(labTree VERSION 0.0.1 LANGUAGES CXX)

# Here is the cmake magic
#https://crascit.com/2015/07/25/cmake-gtest/

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build")

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
                        "${gmock_SOURCE_DIR}/include")
endif()

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

include(GoogleTest)

SET(CES12_SRC "src" CACHE FILEPATH "Directory with student sources")



FILE(GLOB libLabTreeSrc lib/*.cpp)
include_directories( lib )
add_library(libLabTree ${libLabTreeSrc})

FILE(GLOB LabSources ${CES12_SRC}/*.cpp)
include_directories( ${CES12_SRC} )
add_executable(labTreetests test/testTree.cpp ${LabSources})

target_link_libraries(labTreetests gtest gtest_main libLabTree)
 
gtest_discover_tests(labTreetests)




