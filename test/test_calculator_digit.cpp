#include "CppUTest/CommandLineTestRunner.h"
#include <sstream>
#include "model/calculator_digit.h"
#include "model/add.h"
#include "model/subtract.h"
#include "model/multiple.h"
#include <numeric>

TEST_GROUP(CalculatorDigitTestGroup) {};

// CalculatorDigit
TEST(CalculatorDigitTestGroup, initialization)
{
    CalculatorDigit zero{};
    CalculatorDigit one{1};
    CalculatorDigit two{2, 1};
    CHECK_EQUAL(zero.toInt(), 0);
    CHECK_EQUAL(one.toInt(), 1);
    CHECK_EQUAL(two.toInt(), 2);
}

TEST(CalculatorDigitTestGroup, invalid_initialization)
{
    bool exception_threw = false;
    try {
        CalculatorDigit d{2, 0};
    } catch (const std::invalid_argument &e) {
        exception_threw = true;
    }

    CHECK_TRUE(exception_threw);
}

TEST(CalculatorDigitTestGroup, to_int)
{
    CalculatorDigit d{2, 1};
    int actual = d.toInt();
    int expected = 2; 
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitTestGroup, to_double)
{
    CalculatorDigit d{1, 4};
    double actual = d.toDouble();
    double expected = 0.25; 
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitTestGroup, to_set)
{
    CalculatorDigit d{1, 4};
    d.set(10, 2);
    int actual = d.toInt();
    int expected = 5; 
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitTestGroup, test_calculator_digit)
{
    CalculatorDigit d{2, 1};
    int actual = d.toInt();
    int expected = 2; 
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitTestGroup, get_numerator)
{
    CalculatorDigit d{11, 2};
    int actual = d.numerator();
    int expected = 11; 
    CHECK_EQUAL(expected, actual);
}


TEST(CalculatorDigitTestGroup, get_numerator_with_having_gcd)
{
    // 10/2 -> 5/1となり、5が取得されること
    CalculatorDigit d{10, 2};
    int actual = d.numerator();
    int expected = 5; 
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitTestGroup, denominator)
{
    CalculatorDigit d{11, 2};
    int actual = d.denominator();
    int expected = 2; 
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitTestGroup, denominator_with_having_gcd)
{
    // 2/10 -> 1/5となり、5が取得されること
    CalculatorDigit d{2, 10};
    int actual = d.denominator();
    int expected = 5; 
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitTestGroup, isZero)
{
    CalculatorDigit d{0, 1};
    bool result = d.isZero();
    CHECK_TRUE(result);
}


TEST_GROUP(CalculatorDigitOperandTestGroup) {};

TEST(CalculatorDigitOperandTestGroup, operand_plus_1)
{
    CalculatorDigit one = CalculatorDigit{1, 1};
    CalculatorDigit two = CalculatorDigit{2, 1};
    CalculatorDigit three = one + two;
    int actual = three.toInt();
    int expected = 3;
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitOperandTestGroup, operand_plus_2)
{
    CalculatorDigit d1 = CalculatorDigit{1, 3};
    CalculatorDigit d2 = CalculatorDigit{1, 2};
    CalculatorDigit d3 = d1 + d2;
    int expected_numerator = 5; 
    int expected_denominator = 6; 
    int result_numerator = d3.numerator();
    int result_denominator = d3.denominator();
    CHECK_EQUAL(expected_numerator, result_numerator);
    CHECK_EQUAL(expected_denominator, result_denominator);
}


TEST(CalculatorDigitOperandTestGroup, operand_minus)
{
    CalculatorDigit two = CalculatorDigit{2, 1};
    CalculatorDigit five = CalculatorDigit{5, 1};
    CalculatorDigit three = five - two;
    int actual = three.toInt();
    int expected = 3;
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitOperandTestGroup, operand_multiple)
{
    CalculatorDigit two = CalculatorDigit{2, 1};
    CalculatorDigit five = CalculatorDigit{5, 1};
    CalculatorDigit ten = five * two;
    int actual = ten.toInt();
    int expected = 10;
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitOperandTestGroup, operand_divide)
{
    CalculatorDigit two = CalculatorDigit{2, 1};
    CalculatorDigit ten = CalculatorDigit{10, 1};
    CalculatorDigit five = ten / two;
    int actual = five.toInt();
    int expected = 5;
    CHECK_EQUAL(expected, actual);
}

TEST(CalculatorDigitTestGroup, invalid_division)
{
    bool exception_threw = false;
    try {
        CalculatorDigit zero{0, 1};
        CalculatorDigit two{2, 1};
        CalculatorDigit result = two / zero;
    } catch (const std::invalid_argument &e) {
        exception_threw = true;
    }

    CHECK_TRUE(exception_threw);
}

TEST(CalculatorDigitOperandTestGroup, operand_equal)
{
    CalculatorDigit d1 = CalculatorDigit{5, 2};
    CalculatorDigit d2 = CalculatorDigit{10, 4};
    CalculatorDigit d3 = CalculatorDigit{7, 3};
    bool result = d1 == d2;
    CHECK_TRUE(result);

    result = d1 == d3;
    CHECK_FALSE(result);
}

TEST(CalculatorDigitOperandTestGroup, operand_not_equal)
{
    CalculatorDigit d1 = CalculatorDigit{5, 2};
    CalculatorDigit d2 = CalculatorDigit{7, 3};
    CalculatorDigit d3 = CalculatorDigit{10, 4};
    bool result = d1 != d2;
    CHECK_TRUE(result);

    result = d1 != d3;
    CHECK_FALSE(result);
}

TEST(CalculatorDigitOperandTestGroup, operand_cout)
{
    CalculatorDigit d{3, 2};
    std::ostringstream oss;
    oss << d;
    STRCMP_EQUAL("3/2", oss.str().c_str());
}
