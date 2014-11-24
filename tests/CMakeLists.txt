
find_package(GTEST REQUIRED)

file(GLOB SRCS *.cpp)

add_executable(tests ${SRCS})

include_directories(${GTEST_INCLUDE_DIR})

target_link_libraries(tests 
    debug ${GTEST_LIBRARY_DEBUG} optimized ${GTEST_LIBRARY}
    )
