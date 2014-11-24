
find_path(GTEST_HEADER_DIR gtest.h PATHS ${LIBRARY_PATH_HINTS}/*/include/gtest)
get_filename_component(GTEST_INCLUDE_DIR ${GTEST_HEADER_DIR} PATH)

find_library(GTEST_LIBRARY_DEBUG gtestd
    PATHS ${LIBRARY_PATH_HINTS}/*/lib/${ARCH_STR}/Debug/)
find_library(GTEST_LIBRARY gtest
    PATHS ${LIBRARY_PATH_HINTS}/*/lib/${ARCH_STR}/Release/)

if(GTEST_LIBRARY AND GTEST_INCLUDE_DIR AND GTEST_LIBRARY_DEBUG)
    set(GTEST_FOUND True)

    message(STATUS "GTEST library found:")
    message(STATUS "    library : ${GTEST_LIBRARY}, ${GTEST_LIBRARY_DEBUG}")
    message(STATUS "    includes: ${GTEST_INCLUDE_DIR}")
else()
    message(WARNING "GTEST library not found")
    set(GTEST_FOUND False)
endif()

