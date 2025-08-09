#include "model/add.h"
#include "model/calculator_digit.h"

Add::Add(CalculatorDigit operand): operand_{operand} {}

CalculatorDigit Add::execute(CalculatorDigit d)
{
    return d + operand_;
}

CalculatorDigit Add::undo(CalculatorDigit d) const
{
    return d - operand_;
}

void Add::reset(CalculatorDigit d)
{
    operand_ = d;
}
