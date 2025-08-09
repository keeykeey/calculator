#pragma once
#include "model/calculator_command.h"

class Add: public CalculatorCommand {
    CalculatorDigit operand_{};
public:
    explicit Add(CalculatorDigit operand);
    CalculatorDigit execute(CalculatorDigit d) override;
    CalculatorDigit undo(CalculatorDigit d) const override;
    void reset(CalculatorDigit d) override;
};
