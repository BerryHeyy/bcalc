cmake_minimum_required(VERSION 3.12)

project (bcalc VERSION 1.0.0 DESCRIPTION "Berrys Calculator")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Execute commands to get gtkmm include directoreis and library flags. LINUX ONLY
execute_process(
    COMMAND bash -c "pkg-config gtkmm-4.0 --cflags"
    OUTPUT_VARIABLE GTKMM_INCLUDE
)
list(TRANSFORM GTKMM_INCLUDE REPLACE "\n" "") # Remove -I from beginning of include directories, also remove newlines

execute_process(
    COMMAND bash -c "pkg-config gtkmm-4.0 --libs"
    OUTPUT_VARIABLE GTKMM_LIBS
)
list(TRANSFORM GTKMM_LIBS REPLACE "\n" "")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GTKMM_INCLUDE} ${GTKMM_LIBS}")

set(SOURCES
    bcalc.cpp
    main_window.hpp
    main_window.cpp
    util.hpp
    util.hpp
)
list(TRANSFORM SOURCES PREPEND "src/")

add_executable(bcalc ${SOURCES})
