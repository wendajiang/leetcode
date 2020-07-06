cmake_minimum_required(VERSION 3.16)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)
set(leetcodedir clion/leetcode/editor/en)

add_executable(1.test 1.two-sum.cpp)
#add_executable(fudian fudian.cpp)
add_executable(1370 1370.increasing-decreasing-string.cpp)
add_executable(1025 1025.divisor-game.cpp)
#add_executable(199 199.binary-tree-right-side-view.cpp)
add_executable(199.remote ${leetcodedir}/199.binary-tree-right-side-view.cpp)
add_executable(200.remote ${leetcodedir}/200.number-of-islands)