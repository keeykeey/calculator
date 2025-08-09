#include <stdexcept>
#include "model/calculator.h"

Calculator::Calculator(): current_{CalculatorDigit{}} {}
Calculator::Calculator(CalculatorDigit d): current_{d} {}

void Calculator::compute(std::unique_ptr<CalculatorCommand> command)
{
    current_ = command->execute(current_);
    undo_stack_.push(std::move(command));
    redo_stack_ = CommandStack{};
}

void Calculator::undoLast()
{
    if (undo_stack_.empty()) return;
    std::unique_ptr<CalculatorCommand> command = std::move(undo_stack_.top());
    undo_stack_.pop();
    if (!command) {
        throw std::runtime_error("undo_stack contains null command");
    }

    current_ = command->undo(current_);
    redo_stack_.push(std::move(command));
}

void Calculator::redoLast()
{
    if (redo_stack_.empty()) return;
    std::unique_ptr<CalculatorCommand> command = std::move(redo_stack_.top());
    redo_stack_.pop();
    if (!command) {
        throw std::runtime_error("redo_stack contains null command");
    }

    current_ = command->execute(current_);
    undo_stack_.push(std::move(command));
}

CalculatorDigit Calculator::result() const
{
    return current_;
}

void Calculator::clear()
{
    current_ = CalculatorDigit{};
    CommandStack{}.swap(undo_stack_);
    CommandStack{}.swap(redo_stack_);
}
