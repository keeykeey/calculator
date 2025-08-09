#pragma once
#include "model/calculator_digit.h"
#include "model/calculator.h"
#include "controller/calculator_command_factory.h"

class CalculatorController {
    Calculator& calculator_;
    CalculatorCommandFactory& command_factory_;
    std::unique_ptr<CalculatorCommand> current_command_;
    CalculatorDigit current_;

public:
    explicit CalculatorController(
        Calculator& calculator,
        CalculatorCommandFactory& command_factory
    );
    
    int clickDigit(int digit);
    void clickAdd();
    void clickSubtract();
    void clickMultiple();
    void clickDivide();
    void clickClear();
    double clickEqual();
    double clickRedo();
    double clickUndo();
    void clickPoint();
};
