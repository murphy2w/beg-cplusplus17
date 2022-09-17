cmake_minimum_required(VERSION 3.16)
project(begin-cpp17)

# add_definitions("-Wall -g -Wno-unknown-warning-option"
#         " -Wno-format-extra-args -Wno-format -Wno-pragmas"
#         " -Wno-incompatible-pointer-types")

#编译配置选择"Debug"才能调试
set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_STANDARD 17)

include_directories(greedy)

aux_source_directory(. SRC)
# file(GLOB_RECURSE SRC "*.cpp" "*.c")	
# message("--SRC:${SRC}--")
aux_source_directory(greedy SRC2)

add_executable(leetcode ${SRC} ${SRC2})

