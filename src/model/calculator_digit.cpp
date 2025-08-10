#include <stdexcept>
#include <numeric>
#include <iostream>
#include <cassert>
#include "model/calculator_digit.h"

CalculatorDigit::CalculatorDigit(): numerator_{0}, denominator_{1} {}

CalculatorDigit::CalculatorDigit(int numerator): numerator_{numerator}, denominator_{1} {}

CalculatorDigit::CalculatorDigit(int numerator, int denominator)
{
    if (denominator == 0) {
        throw std::invalid_argument("0 denominator");
    }

    int gcd = std::gcd(numerator, denominator);
    numerator_ = numerator / gcd;
    denominator_ = denominator / gcd;
}

int CalculatorDigit::toInt() const
{
    assert(denominator_ != 0);
    return static_cast<int>(numerator_ / denominator_);
}

double CalculatorDigit::toDouble() const
{
    assert(denominator_ != 0);
    return static_cast<double>(numerator_) / static_cast<double>(denominator_);
}

void CalculatorDigit::set(int numerator, int denominator)
{
    if (denominator == 0) {
        throw std::invalid_argument("argument 0 as denominator is invalid");
    }
    int gcd = std::gcd(numerator, denominator);

    numerator_ = numerator / gcd;
    denominator_ = denominator / gcd;
}

int CalculatorDigit::numerator() const
{
    return numerator_;
}

int CalculatorDigit::denominator() const
{
    return denominator_;
}

bool CalculatorDigit::isZero() const
{
    return (numerator_ == 0);
}

CalculatorDigit operator+(const CalculatorDigit& lhs, const CalculatorDigit& rhs)
{
    // lcm: 最小公倍数
    int lhs_dnm = lhs.denominator();
    int rhs_dnm = rhs.denominator();
    int lcm = std::lcm(lhs_dnm, rhs_dnm);

    int lhs_numerator = lhs.numerator() * lcm / lhs_dnm;
    int rhs_numerator = rhs.numerator() * lcm / rhs_dnm;

    int numerator = lhs_numerator + rhs_numerator;

    int gcd = std::gcd(numerator, lcm);
    int num = numerator / gcd;
    int den = lcm / gcd;

    return CalculatorDigit(num, den);
}

CalculatorDigit operator-(const CalculatorDigit& lhs, const CalculatorDigit& rhs)
{
    // lcm: 最小公倍数
    int lhs_dnm = lhs.denominator();
    int rhs_dnm = rhs.denominator();
    int lcm = std::lcm(lhs_dnm, rhs_dnm);

    int lhs_numerator = lhs.numerator() * lcm / lhs_dnm;
    int rhs_numerator = rhs.numerator() * lcm / rhs_dnm;

    int numerator = lhs_numerator - rhs_numerator;

    int gcd = std::gcd(numerator, lcm);
    int num = numerator / gcd;
    int den = lcm / gcd;

    return CalculatorDigit(num, den);
}

CalculatorDigit operator*(const CalculatorDigit& lhs, const CalculatorDigit& rhs)
{
    int numerator = lhs.numerator() * rhs.numerator();
    int denominator = lhs.denominator() * rhs.denominator();

    // gcd: 最大公約数
    int gcd = std::gcd(numerator, denominator);

    numerator = numerator / gcd;
    denominator = denominator / gcd;

    return CalculatorDigit(numerator, denominator);
}

CalculatorDigit operator/(const CalculatorDigit& lhs, const CalculatorDigit& rhs)
{
    if (rhs.numerator() == 0) {
        throw std::runtime_error("division by zero");
    }

    int numerator = lhs.numerator() * rhs.denominator();
    int denominator = lhs.denominator() * rhs.numerator();

    // gcd: 最大公約数
    int gcd = std::gcd(numerator, denominator);

    numerator = numerator / gcd;
    denominator = denominator / gcd;

    return CalculatorDigit(numerator, denominator);
}

bool operator==(const CalculatorDigit& lhs, const CalculatorDigit& rhs)
{
    return (
        lhs.numerator() * rhs.denominator()
        == lhs.denominator() * rhs.numerator()
    );
}

bool operator!=(const CalculatorDigit& lhs, const CalculatorDigit& rhs)
{
    return(
        lhs.numerator() * rhs.denominator()
        != lhs.denominator() * rhs.numerator()
    );
}

std::ostream& operator<<(std::ostream& os, const CalculatorDigit& digit)
{
    os << digit.numerator() <<  "/" << digit.denominator();
    return os;
}
