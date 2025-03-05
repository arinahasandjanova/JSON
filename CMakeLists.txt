cmake_minimum_required(VERSION 3.10)
project(JSON)

set(CMAKE_CXX_STANDARD 14)

add_executable(main
        parser.cpp parser.h tokenizer.h tokenizer.cpp json.h)
