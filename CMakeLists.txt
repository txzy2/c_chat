cmake_minimum_required(VERSION 4.3)
project(test_c C)

set(CMAKE_C_STANDARD 23)

add_executable(test_c main.c
        include/types.h
        include/chat.h
        src/chat.c
        src/chat_message.c
        include/chat_message.h
        include/vector.h)
