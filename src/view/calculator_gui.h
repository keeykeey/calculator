#pragma once
#include <vector>
#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include "view/button.h"
#include "controller/calculator_controller.h"

class CalculatorGui: public QWidget
{
    Q_OBJECT
    QGridLayout *layout;
    QLineEdit *display;
    enum { NUM_DIGIT_BUTTON = 10 };
    std::vector<Button*> digit_button;
    CalculatorController& calculator_controller;
    
public:
    explicit CalculatorGui(
        CalculatorController& CalculatorController,
        QWidget *parent = nullptr
    );

private:
    void initLayout(QGridLayout *layout);
    void initDisplay(QLineEdit *display, QGridLayout *layout);
    void initCalculatorButton(std::vector<Button*> digit_button, QGridLayout *layout);

private slots:
    void clickDigit();
    void clickAdd();
    void clickSubtract();
    void clickMultiple();
    void clickDivide();
    void clickEqual();
    void clickClear();
    void clickRedo();
    void clickUndo();
    void clickPoint();
};
