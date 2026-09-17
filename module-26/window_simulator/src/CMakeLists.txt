add_executable(window_simulator
    main.cpp
    window.cpp
    screen.cpp
)

target_include_directories(window_simulator PRIVATE window_simulator/include)
