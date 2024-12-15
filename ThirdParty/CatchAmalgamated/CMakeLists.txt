project(CatchAmalgamated VERSION 3.7.1)

add_library(${PROJECT_NAME} STATIC
    catch_amalgamated.hpp catch_amalgamated.cpp include/Catch
    )

target_include_directories(${PROJECT_NAME} PUBLIC include)

add_compile_definitions(CATCH_AMALGAMATED_CUSTOM_MAIN)
