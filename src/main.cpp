#include <QApplication>
#include <QPushButton>
#include <cstdlib>
#include "model/calculator.h"
#include "view/calculator_gui.h"
#include "controller/calculator_command_factory.h"
#include "controller/calculator_controller.h"

int main(int argc, char **argv)
{
    // create Qt application
    QApplication app(argc, argv);

    Calculator calculator{};
    CalculatorCommandFactory calculator_command_factory{};

    CalculatorController calculator_controller{calculator, calculator_command_factory};

    // calculatorとcalculator_command_factoryをGUIに依存性注入
    CalculatorGui calculator_gui{calculator_controller};
    calculator_gui.show();

    // exec Qt application
    int result =  app.exec();

    return result;
}
