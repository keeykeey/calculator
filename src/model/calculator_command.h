#pragma once
#include "model/calculator_digit.h"

class CalculatorCommand {
public:
    virtual ~CalculatorCommand() = default;
    virtual CalculatorDigit execute(CalculatorDigit d) = 0;
    virtual CalculatorDigit undo(CalculatorDigit d) const = 0;
    virtual void reset(CalculatorDigit d) = 0;
};

