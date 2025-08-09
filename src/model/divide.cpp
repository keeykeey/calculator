#include <stdexcept>
#include "model/divide.h"

Divide::Divide(CalculatorDigit operand): operand_{operand}{}

CalculatorDigit Divide::execute(CalculatorDigit d)
{
    return d / operand_;
}

CalculatorDigit Divide::undo(CalculatorDigit d) const
{
    if (d.isZero()) {
        // dが0ならば、execute()で0/ operandが実行されたということなので、undo結果は0になる。
        // CalculatorDigit(0, 1) は0の意味。
        return CalculatorDigit(0, 1);
    } else {
        return d * operand_;
    }
}
// operand_をリセットする
void Divide::reset(CalculatorDigit d)
{
    operand_ = d;
}