#pragma once
#include "model/calculator_digit.h"
#include "model/calculator_command.h"

class Divide: public CalculatorCommand {
    CalculatorDigit operand_{};
public:
    explicit Divide(CalculatorDigit operand);
    CalculatorDigit execute(CalculatorDigit d) override;
    CalculatorDigit undo(CalculatorDigit d) const override;
    void reset(CalculatorDigit d) override;
};