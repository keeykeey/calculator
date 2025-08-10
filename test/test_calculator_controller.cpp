#include "CppUTest/CommandLineTestRunner.h"
#include "controller/calculator_command_factory.h"
#include "model/calculator.h"
#include "controller/calculator_controller.h"

TEST_GROUP(CalculatorControllerTestGroup) {
    CalculatorCommandFactory factory{};
    Calculator calculator{CalculatorDigit{}};
};

// CalculatorController
TEST(CalculatorControllerTestGroup, test_click_digit)
{
    CalculatorController c{calculator, factory};
    std::string result = c.clickDigit(10);
    std::string expected = "10";
    CHECK_EQUAL(expected, result);
}

TEST_GROUP(CalculatorControllerCalculationTestGroup) {
    CalculatorCommandFactory factory{};
    Calculator calculator{CalculatorDigit{}};
    CalculatorController controller{calculator, factory};
};

TEST(CalculatorControllerCalculationTestGroup, test_click_point)
{
    controller.clickDigit(0);
    controller.clickPoint();
    std::string result = controller.clickDigit(5);
    std::string expected = "0.5";
    CHECK_EQUAL(expected, result);
    
    controller.clickAdd();
    controller.clickDigit(10);
    controller.clickPoint();
    result = controller.clickDigit(3);
    expected = "10.3";
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorControllerCalculationTestGroup, test_calculation)
{
    controller.clickDigit(1);
    // 1
    controller.clickDigit(0);
    // 10
    controller.clickAdd();
    // 10 + 
    controller.clickDigit(5);
    // 10 + 5
    controller.clickSubtract();
    // 10 + 5 - 
    controller.clickDigit(3);
    // 10 + 5 - 3
    controller.clickMultiple();
    // 12 * 
    controller.clickDigit(2);
    // 12 * 2
    controller.clickDivide();
    // 24 / 
    controller.clickDigit(5);
    // 24 / 5
    double result = controller.clickEqual();
    double expected = 4.8;
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorControllerCalculationTestGroup, test_undo_and_redo)
{
    controller.clickDigit(1);
    controller.clickDigit(0);
    controller.clickAdd();
    controller.clickDigit(5);
    controller.clickSubtract();
    controller.clickDigit(3);
    controller.clickMultiple();
    controller.clickDigit(2);
    controller.clickDivide();
    controller.clickDigit(5);
    controller.clickEqual();
    // 4.8

    controller.clickUndo();
    // 24
    controller.clickUndo();
    // 12
    controller.clickUndo();
    // 15
    double result = controller.clickUndo();
    // 10
    double expected = 10;
    CHECK_EQUAL(expected, result);

    controller.clickRedo();
    // 15
    controller.clickRedo();
    // 12
    result = controller.clickRedo();
    // 24
    expected = 24;
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorControllerCalculationTestGroup, test_undo_and_redo_with_zero_multiplication)
{
    controller.clickDigit(1);
    controller.clickDigit(0);
    controller.clickAdd();
    controller.clickDigit(5);
    controller.clickSubtract();
    controller.clickDigit(3);
    controller.clickMultiple();
    controller.clickDigit(0);
    controller.clickDivide();
    controller.clickDigit(5);
    controller.clickEqual();
    // 0

    controller.clickUndo();
    // 0
    controller.clickUndo();
    // 12
    controller.clickUndo();
    // 15
    double result = controller.clickUndo();
    // 10
    double expected = 10;
    CHECK_EQUAL(expected, result);

    controller.clickRedo();
    // 15
    controller.clickRedo();
    // 12
    result = controller.clickRedo();
    // 0
    expected = 0;
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorControllerCalculationTestGroup, test_undo_and_redo_with_double_value)
{
    controller.clickDigit(1);
    controller.clickPoint();
    controller.clickDigit(5);
    // 1.5
    controller.clickAdd();
    controller.clickDigit(6);
    // 7.5
    double result = controller.clickEqual();

    // 0
    double expected = 7.5;
    CHECK_EQUAL(expected, result);

    // check if initialization after clickEqual() works.
    controller.clickSubtract();
    controller.clickDigit(2);
    controller.clickPoint();
    controller.clickDigit(3);
    // 5.2
    result = controller.clickEqual();
    expected = 5.2;
    CHECK_EQUAL(expected, result);
}


TEST(CalculatorControllerCalculationTestGroup, test_undo_and_redo_with_point)
{
    controller.clickDigit(1);
    controller.clickDigit(0);
    controller.clickAdd();
    controller.clickDigit(5);
    controller.clickPoint();
    controller.clickDigit(5);
    controller.clickSubtract();
    controller.clickDigit(3);
    controller.clickMultiple();
    controller.clickDigit(0);
    controller.clickDivide();
    controller.clickDigit(5);
    controller.clickEqual();
    // 0

    controller.clickUndo();
    // 0
    controller.clickUndo();
    // 12.5
    controller.clickUndo();
    // 15.5
    double result = controller.clickUndo();
    // 10
    double expected = 10;
    CHECK_EQUAL(expected, result);

    controller.clickRedo();
    // 15.5
    controller.clickRedo();
    // 12
    result = controller.clickRedo();
    // 0
    expected = 0;
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorControllerCalculationTestGroup, test_undo_and_redo_with_point_and_0_multiplication)
{
    controller.clickDigit(1);
    controller.clickMultiple();
    controller.clickDigit(2);
    controller.clickMultiple();
    controller.clickDigit(3);
    controller.clickPoint();
    controller.clickDigit(5);
    controller.clickMultiple();
    controller.clickDigit(0);
    controller.clickAdd();
    controller.clickDigit(2);
    controller.clickEqual();
    // 2

    controller.clickUndo();
    // 0
    controller.clickUndo();
    // 6
    controller.clickUndo();
    // 2
    double result = controller.clickUndo();
    // 1

    double expected = 1;
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorControllerCalculationTestGroup, test_undo_and_redo_with_equal)
{
    controller.clickDigit(1);
    controller.clickAdd();
    controller.clickDigit(20);
    controller.clickEqual();
    // 21
    controller.clickSubtract();
    controller.clickDigit(3);
    controller.clickEqual();
    // 18

    controller.clickUndo();
    // 21
    double result = controller.clickUndo();
    // 1
    double expected = 1;
    CHECK_EQUAL(expected, result);
}