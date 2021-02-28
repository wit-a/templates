cmake_minimum_required(VERSION 3.5)

project(templates LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(templates templates.cpp artikel.h artikel.cpp Artikel.csv)
