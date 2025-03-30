cmake_minimum_required(VERSION 3.30)
project(hello C)

#set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD 90)
add_compile_options(-std=c90 -pedantic -Wall -Wextra -ansi)

add_executable(palindrome palindrome.c)