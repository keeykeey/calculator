#include "model/subtract.h"

Subtract::Subtract(CalculatorDigit operand): operand_{operand} {}

CalculatorDigit Subtract::execute(CalculatorDigit d)
{
    return d - operand_;
}

CalculatorDigit Subtract::undo(CalculatorDigit d) const
{
    return d + operand_;
}

void Subtract::reset(CalculatorDigit d)
{
    operand_ = d;
}
