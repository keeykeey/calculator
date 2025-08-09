#pragma once
#include <string>

class CalculatorDigit {
    int numerator_;   // 分子
    int denominator_; // 分母
public:
    explicit CalculatorDigit();
    explicit CalculatorDigit(int numerator);
    explicit CalculatorDigit(int numerator, int denominator);
    int toInt() const;
    double toDouble() const;
    void set(int numerator, int denominator);
    int numerator() const;
    int denominator() const;
    bool isZero() const;
    friend CalculatorDigit operator+(const CalculatorDigit&, const CalculatorDigit&);
    friend CalculatorDigit operator+(const int&, const CalculatorDigit&);
    friend CalculatorDigit operator+(const CalculatorDigit&, const int&);
    friend CalculatorDigit operator-(const CalculatorDigit&, const CalculatorDigit&);
    friend CalculatorDigit operator*(const CalculatorDigit&, const CalculatorDigit&);
    friend CalculatorDigit operator/(const CalculatorDigit&, const CalculatorDigit&);
    friend bool operator==(const CalculatorDigit&, const CalculatorDigit&);
    friend bool operator!=(const CalculatorDigit&, const CalculatorDigit&);
    friend std::ostream& operator<<(std::ostream& os, const CalculatorDigit& digit);
};
