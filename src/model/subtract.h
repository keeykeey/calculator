#pragma once
#include "model/calculator_command.h"

class Subtract: public CalculatorCommand {
    CalculatorDigit operand_{};
public:
    explicit Subtract(CalculatorDigit operand);
    CalculatorDigit execute(CalculatorDigit d) override;
    CalculatorDigit undo(CalculatorDigit d) const override;
    void reset(CalculatorDigit d) override;
};
