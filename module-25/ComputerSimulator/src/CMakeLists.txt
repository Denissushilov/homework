add_executable(ComputerSimulator
    main.cpp
    ram.cpp
    cpu.cpp
    disk.cpp
    gpu.cpp
    kbd.cpp
)

target_include_directories(ComputerSimulator PRIVATE ComputerSimulator/include)