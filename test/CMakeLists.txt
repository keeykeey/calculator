#cppUTest を探す
find_package(CppUTest REQUIRED)

# テスト実行ファイル
add_executable(test_runner
    test.cpp
    test_calculator_digit.cpp
    test_calculator_command.cpp
    test_calculator.cpp
    test_calculator_command_factory.cpp
    test_calculator_controller.cpp
)

# ヘッダーとライブラリのパスを指定
target_include_directories(test_runner PRIVATE
    ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(test_runner
    calculator_lib
    CppUTest::CppUTest
    CppUTest::CppUTestExt
)
