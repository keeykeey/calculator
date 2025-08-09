#include "CppUTest/CommandLineTestRunner.h"
#include "controller/calculator_command_factory.h"
#include "model/add.h"
#include "model/subtract.h"
#include "model/multiple.h"
#include "model/divide.h"

TEST_GROUP(CalculatorCommandFactoryTestGroup) {
    CalculatorCommandFactory factory{};
};

// CalculatorCommandFactory
TEST(CalculatorCommandFactoryTestGroup, test_create_add)
{
    std::unique_ptr<CalculatorCommand> add = factory.createAdd(10);
    int result = add->execute(CalculatorDigit{5}).toInt();
    int expected = 15;
    // if addigion works, assume it's Add
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorCommandFactoryTestGroup, test_create_subtract)
{
    std::unique_ptr<CalculatorCommand> sub = factory.createSubtract(10);
    int result = sub->execute(CalculatorDigit{15}).toInt();
    int expected = 5;
    // if subtraction works, assume it's Subtract
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorCommandFactoryTestGroup, test_create_multiple)
{
    std::unique_ptr<CalculatorCommand> multi = factory.createMultiple(10);
    int result = multi->execute(CalculatorDigit{5}).toInt();
    int expected = 50;
    // if Multiplication works, assume it's Multiple
    CHECK_EQUAL(expected, result);
}

TEST(CalculatorCommandFactoryTestGroup, test_create_divide)
{
    std::unique_ptr<CalculatorCommand> divide = factory.createDivide(10);
    int result = divide->execute(CalculatorDigit{50}).toInt();
    int expected = 5;
    // if Division works, assume it's Divide
    CHECK_EQUAL(expected, result);
}
