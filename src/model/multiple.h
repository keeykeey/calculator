#pragma once
#include <optional>
#include "model/calculator_digit.h"
#include "model/calculator_command.h"

class Multiple: public CalculatorCommand {
    CalculatorDigit operand_{};
    std::optional<CalculatorDigit> prev_value_{};
public:
    explicit Multiple(CalculatorDigit operand);
    CalculatorDigit execute(CalculatorDigit d) override;
    CalculatorDigit undo(CalculatorDigit d) const override;
    void reset(CalculatorDigit d) override;
};
