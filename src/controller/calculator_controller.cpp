#include "controller/calculator_controller.h"
#include "model/calculator_digit.h"
#include "model/divide.h"

CalculatorController::CalculatorController(Calculator& calculator, CalculatorCommandFactory& command_factory)
    :calculator_{calculator}, 
    command_factory_{command_factory},
    current_command_{command_factory_.createAdd(0)},
    current_{CalculatorDigit{0, 1}}
{}

int CalculatorController::clickDigit(int click_value)
{
    CalculatorDigit clicked = CalculatorDigit{click_value, 1};
    CalculatorDigit ten{10, 1};
    current_ = current_ * ten + clicked;
    return current_.toInt();
}

void CalculatorController::clickAdd()
{
    try {
        current_command_->reset(current_);
        calculator_.compute(std::move(current_command_));
        current_ = CalculatorDigit{0, 1};
        current_command_ = command_factory_.createAdd(current_);
    } catch (std::exception e) {
        calculator_.clear();
        current_command_ = nullptr;
        current_command_ = command_factory_.createAdd(0);
        current_ = CalculatorDigit(0, 1);
        throw e;
    }
}

void CalculatorController::clickSubtract()
{
    try {
        current_command_->reset(current_);
        calculator_.compute(std::move(current_command_));
        current_ = CalculatorDigit{0, 1};
        current_command_ = command_factory_.createSubtract(current_);
    } catch (std::exception e) {
        calculator_.clear();
        current_command_ = nullptr;
        current_command_ = command_factory_.createAdd(0);
        current_ = CalculatorDigit(0, 1);
        throw e;
    }
}

void CalculatorController::clickMultiple()
{
    try {
        current_command_->reset(current_);
        calculator_.compute(std::move(current_command_));
        current_ = CalculatorDigit{0, 1};
        current_command_ = command_factory_.createMultiple(current_);
    } catch (std::exception e) {
        calculator_.clear();
        current_command_ = nullptr;
        current_command_ = command_factory_.createAdd(0);
        current_ = CalculatorDigit(0, 1);
        throw e;
    }
}

void CalculatorController::clickDivide()
{
    try {
        current_command_->reset(current_);
        calculator_.compute(std::move(current_command_));
        current_ = CalculatorDigit{0, 1};
        current_command_ = command_factory_.createDivide(current_);
    } catch (std::exception e) {
        calculator_.clear();
        current_command_ = nullptr;
        current_command_ = command_factory_.createAdd(0);
        current_ = CalculatorDigit(0, 1);
        throw e;
    }
}

void CalculatorController::clickClear()
{
    calculator_.clear();
    current_ = CalculatorDigit{0, 1};
}

double CalculatorController::clickEqual()
{
    try {
        current_command_->reset(current_);
        calculator_.compute(std::move(current_command_));
        current_command_ = nullptr;
        current_command_ = command_factory_.createAdd(0);
        current_ = CalculatorDigit{0, 1};
        return calculator_.result().toDouble();
    } catch (std::exception e) {
        calculator_.clear();
        current_command_ = nullptr;
        current_command_ = command_factory_.createAdd(0);
        current_ = CalculatorDigit(0, 1);
        throw e;
    }
}

double CalculatorController::clickRedo()
{
    calculator_.redoLast();
    CalculatorDigit result = calculator_.result();
    return result.toDouble();
}

double CalculatorController::clickUndo()
{
    calculator_.undoLast();
    CalculatorDigit result = calculator_.result();
    return result.toDouble();
}

void CalculatorController::clickPoint()
{
    // TODO
    ;
}
