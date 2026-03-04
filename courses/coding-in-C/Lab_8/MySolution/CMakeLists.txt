cmake_minimum_required(VERSION 3.10)
project(StringUtils C)

set(CMAKE_C_STANDARD 99)

# Include directories
include_directories(include)

# Source files
add_library(string_utils src/string_utils.c)

# Test executable
add_executable(test_string_utils test/test_string_utils.c)
target_link_libraries(test_string_utils string_utils)

# Main executable (optional, for demonstration)
add_executable(main main.c)
target_link_libraries(main string_utils)