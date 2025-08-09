#include <iostream>
#include "controller/calculator_command_factory.h"
#include "model/add.h"
#include "model/subtract.h"
#include "model/multiple.h"
#include "model/divide.h"

std::unique_ptr<CalculatorCommand> CalculatorCommandFactory::createAdd(int digit)
{
    return std::make_unique<Add>(CalculatorDigit{digit, 1});
}

std::unique_ptr<CalculatorCommand> CalculatorCommandFactory::createAdd(CalculatorDigit digit)
{
    return std::make_unique<Add>(digit);
}

std::unique_ptr<CalculatorCommand> CalculatorCommandFactory::createSubtract(int digit)
{
    return std::make_unique<Subtract>(CalculatorDigit{digit, 1});
}

std::unique_ptr<CalculatorCommand> CalculatorCommandFactory::createSubtract(CalculatorDigit digit)
{
    return std::make_unique<Subtract>(digit);
}


std::unique_ptr<CalculatorCommand> CalculatorCommandFactory::createMultiple(int digit)
{
    return std::make_unique<Multiple>(CalculatorDigit{digit, 1});
}

std::unique_ptr<CalculatorCommand> CalculatorCommandFactory::createMultiple(CalculatorDigit digit)
{
    return std::make_unique<Multiple>(digit);
}


std::unique_ptr<CalculatorCommand> CalculatorCommandFactory::createDivide(int digit)
{
    return std::make_unique<Divide>(CalculatorDigit{digit, 1});
}

std::unique_ptr<CalculatorCommand> CalculatorCommandFactory::createDivide(CalculatorDigit digit)
{
    return std::make_unique<Divide>(digit);
}
