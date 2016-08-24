cmake_minimum_required(VERSION 2.8.4)
project(practice)
include(ExternalProject)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# specify with -DCOVERAGE=ON
OPTION(COVERAGE "Set option to enable code coverage reports")

#
#
# googletest
#
#[[
#ExternalProject_Add(
#    googletest
#    GIT_REPOSITORY https://github.com/google/googletest.git
#    INSTALL_COMMAND ""
#    LOG_DOWNLOAD ON
#    LOG_CONFIGURE ON
#    LOG_BUILD ON
#)
#ExternalProject_Get_Property(googletest source_dir)
#include_directories(
#    ${source_dir}/googletest/include
#    ${source_dir}/googlemock/include
#)
#ExternalProject_Get_Property(googletest binary_dir)
#add_library(gtest UNKNOWN IMPORTED)
#add_library(gmock UNKNOWN IMPORTED)
#set_property(TARGET gtest PROPERTY IMPORTED_LOCATION ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
#set_property(TARGET gmock PROPERTY IMPORTED_LOCATION ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock.a)
#add_dependencies(gtest googletest)
#add_dependencies(gmock googletest)
#]]




include_directories(${CMAKE_CURRENT_SOURCE_DIR})


#add_library(testHIDlib UNKNOWN IMPORTED)
#set_property(TARGET testHIDlib PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/external/hidapi/libusb/libhidapi-libusb.so)



#
# hidapi
#
#include (LibFindMacros)

#libfind_pkg_check_modules(libusb_PKGCONF libusb-1.0)

##find_library(libusb_LIBRARY
##  NAMES libusb-1.0
 # PATHS ${libusb_PKGCONF_LIBRARY_DIRS}
##)

##find_path(libusb_INCLUDE_DIR
##  NAMES libusb-1.0/libusb.h
#  PATH_SUFFIXES
#  hidapi
##)

#include(FindPackageHandleStandardArgs)
#find_package_handle_standard_args(HIDAPI
#  DEFAULT_MSG
#  HIDAPI_LIBRARY
#  HIDAPI_INCLUDE_DIR)

##if(libusb_LIBRARY_FOUND)
##  set(libusb_LIBRARY_LIBRARIES "${libusb_LIBRARY}")

##  set(libusb_INCLUDE_DIR" ${libusb_INCLUDE_DIR}")
##endif()

#mark_as_advanced(libusb_INCLUDE_DIR libusb_LIBRARY)


#find_path(libusb_INCLUDE_DIR
#  NAMES libusb.h
#  PATHS ${libusb_PKGCONF_INCLUDE_DIRS}
#  )

#set(libusb_PROCESS_INCLUDES libusb_INCLUDE_DIRS)
#set(libusb_PROCESS_LIBS libusb_LIBRARY)
#libfind_process(libusb)

#include(FindPackageHandleStandardArgs)
#find_package_handle_standard_args(libusb-1.0
#  DEFAULT_MSG
#  libusb_LIBRARY
#  libusb_INCLUDE_DIR)

#if(libusb_FOUND)
# set(libusb_LIBRARY "${LIBUSB_LIBRARY}")

#  set(libusb_INCLUDE_DIRS "${LIBUSB_INCLUDE_DIR}")
#endif()

#mark_as_advanced(libusb_INCLUDE_DIR libusb_LIBRARY)

#
# libhbc
#
#find_library(LIBUSB_LIBRARY
#NAMES libusb libusb-1.0)

#include_directories(include ${libusb_INCLUDE_DIRS})
set(defines -Wall -Wno-unused-variable -Wno-sign-compare -std=c++11 -g3)
if(COVERAGE)
  list(APPEND defines -fprofile-arcs -ftest-coverage)
endif(COVERAGE)
add_definitions(${defines})

#dd_library( src/demoboard.cpp src/hidobj.cpp)
#target_link_libraries(hbc usb-1.0 pthread testHIDlib)

#
# test program
#
#set(hbc_libs hbc)
#if(COVERAGE)
#  list(APPEND hbc_libs gcov --coverage)
#endif(COVERAGE)
add_executable(practice main.cpp linkedlists.cpp matrices.cpp sorting.cpp stringstuff.cpp)



#
# unittest program
#
#add_executable(hbc_unit_test test/testmain.cpp)
#set(test_libs ${hbc_libs} pthread gtest gmock)
#target_link_libraries(hbc_unit_test ${test_libs})

#
# code coverage
#
if(COVERAGE)
  include(CodeCoverage)
  setup_target_for_coverage(hbc_coverage hbc_unit_test coverage)
endif()

