project(LibTests)

add_executable(${PROJECT_NAME}
    main.cpp
    test_Color.cpp
    )

target_link_libraries(${PROJECT_NAME} PRIVATE
    CatchAmalgamated
    LerksyLib
    )