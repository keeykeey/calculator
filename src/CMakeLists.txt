
find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


# ソースファイル群
set(SRC_FILES
    controller/calculator_command_factory.cpp
    controller/calculator_controller.cpp
    model/calculator_digit.cpp
    model/calculator.cpp
    model/add.cpp
    model/subtract.cpp
    model/multiple.cpp
    model/divide.cpp
    view/calculator_gui.cpp
    view/button.cpp
    main.cpp
)

add_library(calculator_lib
    controller/calculator_command_factory.cpp
    controller/calculator_controller.cpp
    model/calculator_digit.cpp
    model/calculator.cpp
    model/add.cpp
    model/subtract.cpp
    model/multiple.cpp
    model/divide.cpp
    view/calculator_gui.cpp
    view/button.cpp
)

target_link_libraries(calculator_lib Qt6::Widgets)

add_executable(calculator main.cpp)
target_link_libraries(calculator calculator_lib)
target_include_directories(calculator_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
