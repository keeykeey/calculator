#include "CppUTest/CommandLineTestRunner.h"
#include "model/calculator_digit.h"
#include "model/calculator.h"
#include "model/add.h"
#include "model/subtract.h"

TEST_GROUP(CalculatorTestClass) {};

// Calculator
TEST(CalculatorTestClass, test_initializaion_1)
{
    Calculator calculator{};
    int expected = 0;
    int result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorTestClass, test_initializaion_2)
{
    CalculatorDigit d{2, 1};
    Calculator calculator{d};
    int expected = 2;
    int result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorTestClass, test_compute)
{
    Calculator calculator{};
    std::unique_ptr<Add> add_two = std::make_unique<Add>(CalculatorDigit{2, 1});
    std::unique_ptr<Add> add_five = std::make_unique<Add>(CalculatorDigit{5, 1});
    std::unique_ptr<Subtract> sub_one = std::make_unique<Subtract>(CalculatorDigit{1, 1});

    calculator.compute(std::move(add_two));
    int expected = 2;
    int result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);

    calculator.compute(std::move(add_five));
    expected = 7;
    result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);

    calculator.compute(std::move(sub_one));
    expected = 6;
    result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorTestClass, test_undoLast)
{
    Calculator calculator{};
    std::unique_ptr<Add> add_two = std::make_unique<Add>(CalculatorDigit{2, 1});
    std::unique_ptr<Add> add_five = std::make_unique<Add>(CalculatorDigit{5, 1});
    std::unique_ptr<Subtract> sub_one = std::make_unique<Subtract>(CalculatorDigit{1, 1});
    calculator.compute(std::move(add_two));
    calculator.compute(std::move(add_five));
    calculator.compute(std::move(sub_one));

    calculator.undoLast();
    int expected = 7;
    int result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);

    calculator.undoLast();
    expected = 2;
    result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorTestClass, test_redoLast)
{
    Calculator calculator{};
    std::unique_ptr<Add> add_two = std::make_unique<Add>(CalculatorDigit{2, 1});
    std::unique_ptr<Add> add_five = std::make_unique<Add>(CalculatorDigit{5, 1});
    std::unique_ptr<Subtract> sub_one = std::make_unique<Subtract>(CalculatorDigit{1, 1});
    calculator.compute(std::move(add_two));
    calculator.compute(std::move(add_five));
    calculator.compute(std::move(sub_one));
    calculator.undoLast();
    calculator.undoLast();
    calculator.undoLast();

    calculator.redoLast();
    int expected = 2;
    int result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);

    calculator.redoLast();
    expected = 7;
    result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);

    calculator.redoLast();
    expected = 6;
    result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorTestClass, test_clear)
{
    Calculator calculator{};
    std::unique_ptr<Add> add_two = std::make_unique<Add>(CalculatorDigit{2, 1});
    std::unique_ptr<Add> add_five = std::make_unique<Add>(CalculatorDigit{5, 1});
    std::unique_ptr<Subtract> sub_one = std::make_unique<Subtract>(CalculatorDigit{1, 1});
    calculator.compute(std::move(add_two));
    calculator.clear();
    int expected = 0;
    int result = calculator.result().toInt();
    CHECK_EQUAL(expected, result);
}
