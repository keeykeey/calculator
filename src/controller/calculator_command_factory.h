#pragma once
#include <memory>
#include <optional>
#include "model/calculator_digit.h"
#include "model/calculator_command.h"

class CalculatorCommandFactory {
public:
    explicit CalculatorCommandFactory(){};
    std::unique_ptr<CalculatorCommand> createAdd(int digit);
    std::unique_ptr<CalculatorCommand> createAdd(CalculatorDigit digit);
    std::unique_ptr<CalculatorCommand> createSubtract(int digit);
    std::unique_ptr<CalculatorCommand> createSubtract(CalculatorDigit digit);
    std::unique_ptr<CalculatorCommand> createMultiple(int digit);
    std::unique_ptr<CalculatorCommand> createMultiple(CalculatorDigit digit);
    std::unique_ptr<CalculatorCommand> createDivide(int digit);
    std::unique_ptr<CalculatorCommand> createDivide(CalculatorDigit digit);
};
