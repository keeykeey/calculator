#include <exception>
#include "view/calculator_gui.h" 
#include "model/add.h"
#include "model/subtract.h"

CalculatorGui::CalculatorGui(
    CalculatorController& calculator_controller,
    QWidget *parent
)
    :QWidget(parent),
    layout{new QGridLayout{this}},
    display{new QLineEdit{"0", this}},
    digit_button{},
    calculator_controller(calculator_controller)
{
    // Init Layout
    initLayout(layout);

    // Init Display
    initDisplay(display, layout);

    // Init Calculator Button
    initCalculatorButton(digit_button, layout);

    setLayout(layout);

    setWindowTitle(tr("Calculator"));
}

void CalculatorGui::clickDigit()
{
    Button *clicked_button = qobject_cast<Button *>(sender());
    int click_value = clicked_button->text().toInt();
    std::string display_value = calculator_controller.clickDigit(click_value);
    display->setText(tr(display_value.c_str()));
}

void CalculatorGui::clickAdd()
{
    calculator_controller.clickAdd();
}

void CalculatorGui::clickSubtract()
{
    calculator_controller.clickSubtract();
}

void CalculatorGui::clickMultiple()
{
    calculator_controller.clickMultiple();
}

void CalculatorGui::clickDivide()
{
    calculator_controller.clickDivide();
}

void CalculatorGui::clickEqual()
{
    try {
        double result = calculator_controller.clickEqual();
        display->setText(QString::number(result));
    } catch (std::exception e) {
        display->setText(tr("無効な計算です。"));
    }
}

void CalculatorGui::clickClear()
{
    calculator_controller.clickClear();
    display->setText(QString::number(0));
}

void CalculatorGui::clickRedo()
{
    try {
        double result = calculator_controller.clickRedo();
        display->setText(QString::number(result));
    } catch (std::exception e) {
        display->setText(tr("redoに失敗しました。"));
    }
}

void CalculatorGui::clickUndo()
{
    try {
        double result = calculator_controller.clickUndo();
        display->setText(QString::number(result));
    } catch (std::exception e) {
        display->setText(tr("undoに失敗しました。"));
    }
}

void CalculatorGui::clickPoint()
{
    std::string display_value = calculator_controller.clickPoint();
    display->setText(tr(display_value.c_str()));
}

void CalculatorGui::initDisplay(QLineEdit *display, QGridLayout *layout)
{
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);
    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);
    layout->addWidget(display, 0, 0, 1, 6);
}

void CalculatorGui::initLayout(QGridLayout *layout)
{
    layout->setSizeConstraint(QLayout::SetFixedSize);
}

void CalculatorGui::initCalculatorButton(std::vector<Button*> digit_button, QGridLayout *layout)
{
    Button *undo_btn = new Button(tr("undo"), this);
    connect(undo_btn, &Button::clicked, this, &CalculatorGui::clickUndo);
    layout->addWidget(undo_btn, 2, 1, 1, 1);

    Button *redo_btn = new Button(tr("redo"), this);
    connect(redo_btn, &Button::clicked, this, &CalculatorGui::clickRedo);
    layout->addWidget(redo_btn, 2, 2, 1, 1);

    Button *clear_btn = new Button(tr("clear"), this);
    connect(clear_btn, &Button::clicked, this, &CalculatorGui::clickClear);
    layout->addWidget(clear_btn, 2, 3, 1, 2);

    for (int i = 1; i < NUM_DIGIT_BUTTON; ++i)
    {
        int row = ((9 - i) / 3) + 3;
        int column = ((i - 1) % 3) + 1;
        Button *btn = new Button(QString::number(i), this);
        connect(btn, &Button::clicked, this, &CalculatorGui::clickDigit);
        layout->addWidget(btn, row , column, 1, 1);
        digit_button.push_back(btn);
    }

    Button *point_btn = new Button(tr("."), this);
    connect(point_btn, &Button::clicked, this, &CalculatorGui::clickPoint);
    layout->addWidget(point_btn, 3, 4, 1, 1);

    Button *multiple_btn = new Button(tr("\303\227"), this);
    connect(multiple_btn, &Button::clicked, this, &CalculatorGui::clickMultiple);
    layout->addWidget(multiple_btn, 4, 4, 1, 1);

    Button *divide_btn = new Button(tr("\303\267"), this);
    connect(divide_btn, &Button::clicked, this, &CalculatorGui::clickDivide);
    layout->addWidget(divide_btn, 5, 4, 1, 1);

    Button *zero_btn = new Button(QString::number(0), this);
    connect(zero_btn, &Button::clicked, this, &CalculatorGui::clickDigit);
    layout->addWidget(zero_btn, 6, 1, 1, 1);

    Button *add_btn = new Button(tr("+"), this);
    connect(add_btn, &Button::clicked, this, &CalculatorGui::clickAdd);
    layout->addWidget(add_btn, 6, 2, 1, 1);

    Button *subtract_btn = new Button(tr("-"), this);
    connect(subtract_btn, &Button::clicked, this, &CalculatorGui::clickSubtract);
    layout->addWidget(subtract_btn, 6, 3, 1, 1);

    Button *execute_btn = new Button(tr("="), this);
    connect(execute_btn, &Button::clicked, this, &CalculatorGui::clickEqual);
    layout->addWidget(execute_btn, 6, 4, 1, 1);

}
