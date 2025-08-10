#include <stdexcept>
#include "model/multiple.h"

Multiple::Multiple(CalculatorDigit operand): operand_{operand}{}

CalculatorDigit Multiple::execute(CalculatorDigit d)
{
    prev_value_.emplace(d);
    return d * operand_;
}

CalculatorDigit Multiple::undo(CalculatorDigit d) const
{
    if (operand_.isZero()) {
        // operandが0の場合、undoでもとの値を導けないため、保存していたprev_value_を返す。
        if (prev_value_.has_value()) {
            return prev_value_.value();
        } else {
            throw std::runtime_error("invalid undo before execute()");
        }
    } else if (d.isZero()) {
        // dが0でoperand!=0のときは、undoしたあとの値が0ということになる。
        return CalculatorDigit(0);
    } else {
        return d / operand_;
    }
}
// operand_をリセットする
void Multiple::reset(CalculatorDigit d)
{
    prev_value_.reset();
    operand_ = d;
}
