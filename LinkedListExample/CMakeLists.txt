cmake_minimum_required(VERSION 3.1)

project(LinkedListExample LANGUAGES C)


add_library(
LinkedList STATIC
lib/LinkedList.h
lib/LinkedList.c
)

add_executable(LinkedListExample main.c)

target_link_libraries(LinkedListExample PRIVATE LinkedList)
