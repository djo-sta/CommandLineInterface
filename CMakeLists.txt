cmake_minimum_required(VERSION 3.10)
project(apk)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(apk
    main.cpp
    Emulator/emulator.cpp
    AbstractCommands/command.cpp
    AbstractCommands/time_command.cpp
    AbstractCommands/file_command.cpp
    AbstractCommands/arg_command.cpp
    Commands/date.cpp
    Commands/time.cpp
    Commands/rm.cpp
    Commands/touch.cpp
    Commands/truncate.cpp
    Commands/echo.cpp
    Commands/prompt.cpp
    Commands/wc.cpp
    Commands/tr.cpp
    Commands/head.cpp
    Commands/batch.cpp
    )

target_include_directories(apk PRIVATE
    AbstractCommands,
    Commands,
    Emulator,
)
