#include <sstream>
#include "CppUTest/CommandLineTestRunner.h"
#include "model/calculator_digit.h"
#include "model/add.h"
#include "model/subtract.h"
#include "model/multiple.h"
#include "model/divide.h"

TEST_GROUP(AddCommandTestGroup) {};
TEST_GROUP(SubtractCommandTestGroup) {};
TEST_GROUP(MultipleCommandTestGroup) {};
TEST_GROUP(DivideCommandTestGroup) {};

// Add
TEST(AddCommandTestGroup, TestAddExecuteWhenInteger)
{
    CalculatorDigit operand{1, 1};
    CalculatorDigit digit{0, 1};
    Add add{operand};
    CalculatorDigit result = add.execute(digit);
    int actual = result.toInt();
    int expected = 1;
    CHECK_EQUAL(expected, actual);
}

TEST(AddCommandTestGroup, TestAddUndoWhenInteger)
{
    CalculatorDigit operand{1, 1};
    CalculatorDigit digit{3, 1};
    Add add{operand};
    CalculatorDigit result = add.undo(digit);
    int actual = result.toInt();
    int expected = 2;
    CHECK_EQUAL(expected, actual);
}

TEST(AddCommandTestGroup, TestAddExecuteWhenNegativeInteger)
{
    CalculatorDigit operand{-1, 1};
    CalculatorDigit digit{3, 1};
    Add add{operand};
    CalculatorDigit result = add.execute(digit);
    int actual = result.toInt();
    int expected = 2;
    CHECK_EQUAL(expected, actual);
}

TEST(AddCommandTestGroup, TestAddUndoWhenNegativeInteger)
{
    CalculatorDigit operand{-1, 1};
    CalculatorDigit digit{2, 1};
    Add add{operand};
    CalculatorDigit result = add.undo(digit);
    int actual = result.toInt();
    int expected = 3;
    CHECK_EQUAL(expected, actual);
}

TEST(AddCommandTestGroup, TestAddExecuteWhenFraction)
{
    CalculatorDigit operand{3, 2};
    CalculatorDigit digit{7, 5};
    Add add{operand};
    CalculatorDigit result = add.execute(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("29/10", oss.str().c_str());
}

TEST(AddCommandTestGroup, TestAddUndoWhenFraction)
{
    CalculatorDigit operand{3, 2};
    CalculatorDigit digit{29, 10};
    Add add{operand};
    CalculatorDigit result = add.undo(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("7/5", oss.str().c_str());
}

TEST(AddCommandTestGroup, TestAddExecuteWhenReducibleFraction)
{
    CalculatorDigit operand{17, 20};
    CalculatorDigit digit{13, 20};
    Add add{operand};
    CalculatorDigit result = add.execute(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("3/2", oss.str().c_str());
}

TEST(AddCommandTestGroup, TestAddUndoWhenReducibleFraction)
{
    CalculatorDigit operand{17, 20};
    CalculatorDigit digit{3, 2};
    Add add{operand};
    CalculatorDigit result = add.undo(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("13/20", oss.str().c_str());
}

TEST(AddCommandTestGroup, TestAddExecuteAndUndoManyTimes)
{
    CalculatorDigit operand1{3, 2};
    CalculatorDigit operand2{0, 1};
    CalculatorDigit operand3{4, 17};
    CalculatorDigit operand4{1, 1};
    CalculatorDigit digit{3, 1};
    Add add1{operand1};
    Add add2{operand2};
    Add add3{operand3};
    Add add4{operand4};
    CalculatorDigit result = add1.execute(digit);
    result = add2.execute(result);
    result = add3.execute(result);
    result = add4.execute(result);
    result = add4.undo(result);
    result = add3.undo(result);
    result = add2.undo(result);
    result = add1.undo(result);
    CHECK_TRUE(digit == result);
}

TEST(AddCommandTestGroup, TestAddReset)
{
    CalculatorDigit zero{};
    CalculatorDigit operand{1, 1};
    CalculatorDigit digit{3, 1};
    Add add{zero};
    add.reset(operand);
    CalculatorDigit result = add.undo(digit);
    int actual = result.toInt();
    int expected = 2;
    CHECK_EQUAL(expected, actual);
}

// Subtract
TEST(SubtractCommandTestGroup, TesteSubtractExecuteWhenInteger)
{
    CalculatorDigit operand{1, 1};
    CalculatorDigit digit{3, 1};
    Subtract sub{operand};
    CalculatorDigit result = sub.execute(digit);
    int actual = result.toInt();
    int expected = 2;
    CHECK_EQUAL(expected, actual);
}

TEST(SubtractCommandTestGroup, TestSubtractUndoWhenInteger)
{
    CalculatorDigit operand{1, 1};
    CalculatorDigit digit{3, 1};
    Subtract sub{operand};
    CalculatorDigit result = sub.undo(digit);
    int actual = result.toInt();
    int expected = 4;
    CHECK_EQUAL(expected, actual);
}

TEST(SubtractCommandTestGroup, TesteSubtractExecuteWhenNegativeInteger)
{
    CalculatorDigit operand{-2, 1};
    CalculatorDigit digit{3, 1};
    Subtract sub{operand};
    CalculatorDigit result = sub.execute(digit);
    int actual = result.toInt();
    int expected = 5;
    CHECK_EQUAL(expected, actual);
}

TEST(SubtractCommandTestGroup, TestSubtractUndoWhenNevativeInteger)
{
    CalculatorDigit operand{-2, 1};
    CalculatorDigit digit{5, 1};
    Subtract sub{operand};
    CalculatorDigit result = sub.undo(digit);
    int actual = result.toInt();
    int expected = 3;
    CHECK_EQUAL(expected, actual);
}

TEST(SubtractCommandTestGroup, TestSubtractExecuteWhenFraction)
{
    CalculatorDigit operand{6, 5};
    CalculatorDigit digit{3, 2};
    Subtract sub{operand};
    CalculatorDigit result = sub.execute(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("3/10", oss.str().c_str());
}

TEST(SubtractCommandTestGroup, TestSubtractUndoWhenFraction)
{
    CalculatorDigit operand{6, 5};
    CalculatorDigit digit{3, 10};
    Subtract sub{operand};
    CalculatorDigit result = sub.undo(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("3/2", oss.str().c_str());
}

TEST(SubtractCommandTestGroup, TestSubtractExecuteWhenReducibleFraction)
{
    CalculatorDigit operand{13, 20};
    CalculatorDigit digit{17, 20};
    Subtract sub{operand};
    CalculatorDigit result = sub.execute(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("1/5", oss.str().c_str());
}

TEST(SubtractCommandTestGroup, TestSubtractUndoWhenReducibleFraction)
{
    CalculatorDigit operand{13, 20};
    CalculatorDigit digit{1, 5};
    Subtract sub{operand};
    CalculatorDigit result = sub.undo(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("17/20", oss.str().c_str());
}

TEST(SubtractCommandTestGroup, TestSubtractExecuteAndUndoManyTimes)
{
    CalculatorDigit operand1{3, 2};
    CalculatorDigit operand2{0, 1};
    CalculatorDigit operand3{4, 17};
    CalculatorDigit operand4{1, 1};
    CalculatorDigit digit{3, 1};
    Subtract sub1{operand1};
    Subtract sub2{operand2};
    Subtract sub3{operand3};
    Subtract sub4{operand4};
    CalculatorDigit result = sub1.execute(digit);
    result = sub2.execute(result);
    result = sub3.execute(result);
    result = sub4.execute(result);
    result = sub4.undo(result);
    result = sub3.undo(result);
    result = sub2.undo(result);
    result = sub1.undo(result);
    CHECK_TRUE(digit == result);
}

TEST(SubtractCommandTestGroup, TestSubtractReset)
{
    CalculatorDigit zero{};
    CalculatorDigit operand{1, 1};
    CalculatorDigit digit{3, 1};
    Subtract sub{zero};
    sub.reset(operand);
    CalculatorDigit result = sub.undo(digit);
    int actual = result.toInt();
    int expected = 4;
    CHECK_EQUAL(expected, actual);
}

// Multiple
TEST(MultipleCommandTestGroup, TesteMultipleExecuteWhenInteger)
{
    CalculatorDigit operand{2, 1};
    CalculatorDigit digit{3, 1};
    Multiple multiple{operand};
    CalculatorDigit result = multiple.execute(digit);
    int actual = result.toInt();
    int expected = 6;
    CHECK_EQUAL(expected, actual);
}

TEST(MultipleCommandTestGroup, TestMultipleUndoWhenInteger)
{
    CalculatorDigit operand{2, 1};
    CalculatorDigit digit{12, 1};
    Multiple multiple{operand};
    CalculatorDigit result = multiple.undo(digit);
    int actual = result.toInt();
    int expected = 6;
    CHECK_EQUAL(expected, actual);
}

TEST(MultipleCommandTestGroup, TesteMultipleExecuteWhenNegativeInteger)
{
    CalculatorDigit operand{-2, 1};
    CalculatorDigit digit{3, 1};
    Multiple multiple{operand};
    CalculatorDigit result = multiple.execute(digit);
    int actual = result.toInt();
    int expected = -6;
    CHECK_EQUAL(expected, actual);
}

TEST(MultipleCommandTestGroup, TestMultipleUndoWhenNegativeInteger)
{
    CalculatorDigit operand{-2, 1};
    CalculatorDigit digit{-12, 1};
    Multiple multiple{operand};
    CalculatorDigit result = multiple.undo(digit);
    int actual = result.toInt();
    int expected = 6;
    CHECK_EQUAL(expected, actual);
}

TEST(MultipleCommandTestGroup, TesteMultipleExecuteWhenFraction)
{
    CalculatorDigit operand{11, 3};
    CalculatorDigit digit{2, 5};
    Multiple multiple{operand};
    CalculatorDigit result = multiple.execute(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("22/15", oss.str().c_str());
}

TEST(MultipleCommandTestGroup, TestMultipleUndoWhenFraction)
{
    CalculatorDigit operand{11, 3};
    CalculatorDigit digit{22, 15};
    Multiple multiple{operand};
    CalculatorDigit result = multiple.undo(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("2/5", oss.str().c_str());
}

TEST(MultipleCommandTestGroup, TesteMultipleExecuteWhenReducibleFraction)
{
    CalculatorDigit operand{4, 3};
    CalculatorDigit digit{21, 8};
    Multiple multiple{operand};
    CalculatorDigit result = multiple.execute(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("7/2", oss.str().c_str());
}

TEST(MultipleCommandTestGroup, TestMultipleUndoWhenReducibleFraction)
{
    CalculatorDigit operand{4, 3};
    CalculatorDigit digit{7, 2};
    Multiple multiple{operand};
    CalculatorDigit result = multiple.undo(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("21/8", oss.str().c_str());
}

TEST(MultipleCommandTestGroup, TestMultipleExecuteAndUndoManyTimes)
{
    CalculatorDigit operand1{3, 2};
    CalculatorDigit operand2{0, 3};
    CalculatorDigit operand3{4, 17};
    CalculatorDigit operand4{1, 1};
    CalculatorDigit digit{3, 1};
    Multiple multiple1{operand1};
    Multiple multiple2{operand2};
    Multiple multiple3{operand3};
    Multiple multiple4{operand4};
    CalculatorDigit result = multiple1.execute(digit);
    result = multiple2.execute(result);
    result = multiple3.execute(result);
    result = multiple4.execute(result);
    result = multiple4.undo(result);
    result = multiple3.undo(result);
    result = multiple2.undo(result);
    result = multiple1.undo(result);
    CHECK_TRUE(digit == result);
}

TEST(MultipleCommandTestGroup, TestMultipleReset)
{
    CalculatorDigit zero{};
    CalculatorDigit operand{2, 1};
    CalculatorDigit digit{12, 1};
    Multiple mul{zero};
    mul.reset(operand);
    CalculatorDigit result = mul.undo(digit);
    int actual = result.toInt();
    int expected = 6;
    CHECK_EQUAL(expected, actual);
}

// Divide
TEST(DivideCommandTestGroup, TesteDivideExecuteWhenInteger)
{
    CalculatorDigit operand{3, 1};
    CalculatorDigit digit{15, 1};
    Divide div{operand};
    CalculatorDigit result = div.execute(digit);
    int actual = result.toInt();
    int expected = 5;
    CHECK_EQUAL(expected, actual);
}

TEST(DivideCommandTestGroup, TestDivideUndoWhenInteger)
{
    CalculatorDigit operand{3, 1};
    CalculatorDigit digit{5, 1};
    Divide div{operand};
    CalculatorDigit result = div.undo(digit);
    int actual = result.toInt();
    int expected = 15;
    CHECK_EQUAL(expected, actual);
}

TEST(DivideCommandTestGroup, TesteDivideExecuteWhenNegativeInteger)
{
    CalculatorDigit operand{-3, 1};
    CalculatorDigit digit{15, 1};
    Divide div{operand};
    CalculatorDigit result = div.execute(digit);
    int actual = result.toInt();
    int expected = -5;
    CHECK_EQUAL(expected, actual);
}

TEST(DivideCommandTestGroup, TestDivideUndoWhenNegativeInteger)
{
    CalculatorDigit operand{-3, 1};
    CalculatorDigit digit{-5, 1};
    Divide div{operand};
    CalculatorDigit result = div.undo(digit);
    int actual = result.toInt();
    int expected = 15;
    CHECK_EQUAL(expected, actual);
}

TEST(DivideCommandTestGroup, TesteDivideExecuteWhenFraction)
{
    CalculatorDigit operand{7, 3};
    CalculatorDigit digit{13, 5};
    Divide div{operand};
    CalculatorDigit result = div.execute(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("39/35", oss.str().c_str());
}

TEST(DivideCommandTestGroup, TestDivideUndoWhenFraction)
{
    CalculatorDigit operand{7, 3};
    CalculatorDigit digit{39, 35};
    Divide div{operand};
    CalculatorDigit result = div.undo(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("13/5", oss.str().c_str());
}

TEST(DivideCommandTestGroup, TesteDivideExecuteWhenReducibleFraction)
{
    CalculatorDigit operand{7, 3};
    CalculatorDigit digit{21, 5};
    Divide div{operand};
    CalculatorDigit result = div.execute(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("9/5", oss.str().c_str());
}

TEST(DivideCommandTestGroup, TestDivideUndoWhenReducibleFraction)
{
    CalculatorDigit operand{7, 3};
    CalculatorDigit digit{9, 5};
    Divide div{operand};
    CalculatorDigit result = div.undo(digit);
    std::ostringstream oss;
    oss << result;
    STRCMP_EQUAL("21/5", oss.str().c_str());
}

TEST(DivideCommandTestGroup, TestDivideExecuteAndUndoManyTimes)
{
    CalculatorDigit operand1{3, 2};
    CalculatorDigit operand2{5, 1};
    CalculatorDigit operand3{4, 17};
    CalculatorDigit operand4{1, 1};
    CalculatorDigit digit{3, 1};
    Divide divide1{operand1};
    Divide divide2{operand2};
    Divide divide3{operand3};
    Divide divide4{operand4};
    CalculatorDigit result = divide1.execute(digit);
    result = divide2.execute(result);
    result = divide3.execute(result);
    result = divide4.execute(result);
    result = divide4.undo(result);
    result = divide3.undo(result);
    result = divide2.undo(result);
    result = divide1.undo(result);
    CHECK_TRUE(digit == result);
}

TEST(DivideCommandTestGroup, TestDivideReset)
{
    CalculatorDigit zero{};
    CalculatorDigit operand{3, 1};
    CalculatorDigit digit{5, 1};
    Divide div{operand};
    div.reset(operand);
    CalculatorDigit result = div.undo(digit);
    int actual = result.toInt();
    int expected = 15;
    CHECK_EQUAL(expected, actual);
}
