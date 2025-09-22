add_library(date STATIC "date.cpp" "date.hpp")

target_include_directories(date PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})