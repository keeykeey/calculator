#pragma once
#include <stack>
#include <memory>
#include "model/calculator_command.h"
#include "model/calculator_digit.h"

class Calculator {
    using CommandStack = std::stack<std::unique_ptr<CalculatorCommand>>;

    CalculatorDigit current_{};
    CommandStack undo_stack_;
    CommandStack redo_stack_;

public:
    explicit Calculator();
    explicit Calculator(CalculatorDigit d);
    void compute(std::unique_ptr<CalculatorCommand> command);
    void undoLast();
    void redoLast();
    CalculatorDigit result() const;
    void clear();
};
