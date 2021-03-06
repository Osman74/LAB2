#include "Calculator.h"
#include <math.h>

QPushButton* Calculator::createButton(const QString& str)
{
    QPushButton* pcmd = new QPushButton(str);
    pcmd->setMinimumSize(40, 40);
    connect(pcmd, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    if (str == "pi")
    {
        pcmd->setStyleSheet("border: 1px solid gray;");
        return pcmd;
    }
    if (str.contains(QRegExp("[0-9]")) && (!str.contains(QRegExp("[/^]"))))
    {
        pcmd->setStyleSheet("border: 1px solid gray;");
        return pcmd;
    }
    if(str.contains("CE"))
    {
        pcmd->setStyleSheet("background-color: rgb(215, 215, 215); border: 1px solid gray; border-radius:50px;");
        return pcmd;
    }
    pcmd->setStyleSheet("background-color: rgb(255, 151, 57); color: white; border: 1px solid gray;");
    return pcmd;
}

Calculator::Calculator(QWidget* pwgt/*= 0*/) : QWidget(pwgt)
{
    m_rb1 = new QRadioButton("Обычный");
    m_rb1->setChecked(true);
    m_rb2 = new QRadioButton("Инженерный");
    connect(m_rb1, SIGNAL(clicked()), SLOT(radioButton1Clicked()));
    connect(m_rb2, SIGNAL(clicked()), SLOT(radioButton2Clicked()));
    m_plcd = new QLCDNumber(12);
    m_plcd->setSegmentStyle(QLCDNumber::Flat);
    m_plcd->setMinimumSize(150, 50);
    QString aButtons[4][5] = {
        {"7", "8", "9", "/", "sqrt"},
        {"4", "5", "6", "*", "1/x"},
        {"1", "2", "3", "-"},
        {"0", ".", "=", "+"}
    };
    //Layout setup
    m_Layout = new QGridLayout;
    m_Layout->addWidget(m_plcd, 0, 0, 1, 5);
    m_Layout->addWidget(m_rb1, 1, 0);
    m_Layout->addWidget(m_rb2, 1, 1);
    m_Layout->addWidget(createButton("CE"), 1, 4);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            m_Layout->addWidget(createButton(aButtons[i][j]), i + 2, j);
        }
     }
     for (int i = 2; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            m_Layout->addWidget(createButton(aButtons[i][j]), i + 2, j);
        }
     }
     setLayout(m_Layout);
     setFixedSize(400, 370);
     setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
     setWindowTitle("Калькулятор(Обычный)");
}

void Calculator::CommonCalculator()
{
    m_Layout->addWidget(m_plcd, 0, 0, 1, 5);
    QLayoutItem *item=m_Layout->itemAtPosition(1,8);
    QWidget *i=item->widget();
    if(i)
    {
        m_Layout->removeWidget(i);
        delete i;
    }
    for(int k = 0; k < 2; ++k)
    {
        for (int j = 0; j < 9; ++j)
        {
            QLayoutItem *item=m_Layout->itemAtPosition(k + 2,j);
            QWidget *i=item->widget();
            if(i)
            {
            m_Layout->removeWidget(i);
            delete i;
            }
        }
    }
    for(int k = 2; k < 4; ++k)
    {
        for (int j = 0; j < 8; ++j)
        {
            QLayoutItem *item=m_Layout->itemAtPosition(k + 2,j);
            QWidget *i=item->widget();
            if(i)
            {
                m_Layout->removeWidget(i);
                delete i;
            }
        }
    }
    m_Layout->addWidget(createButton("CE"), 1, 4);
    QString aButtons[4][5] = {{"7", "8", "9", "/", "sqrt"},
                           {"4", "5", "6", "*", "1/x"},
                           {"1", "2", "3", "-"},
                           {"0", ".", "=", "+"}
    };
    //Layout setup
    for (int i = 0; i < 2; ++i) {
       for (int j = 0; j < 5; ++j) {
           m_Layout->addWidget(createButton(aButtons[i][j]), i + 2, j);
       }
    }
    for (int i = 2; i < 4; ++i) {
       for (int j = 0; j < 4; ++j) {
           m_Layout->addWidget(createButton(aButtons[i][j]), i + 2, j);
       }
    }
    setFixedSize(400, 370);
    setWindowTitle("Калькулятор(Обычный)");
}

void Calculator::EngineerCalculator()
{
    m_Layout->addWidget(m_plcd, 0, 0, 1, 9);
    QLayoutItem *item=m_Layout->itemAtPosition(1,4);
    QWidget *i=item->widget();
    if(i)
    {
        m_Layout->removeWidget(i);
        delete i;
    }
    for(int k = 0; k < 2; ++k)
    {
        for (int j = 0; j < 5; ++j)
        {
            QLayoutItem *item=m_Layout->itemAtPosition(k + 2,j);
            QWidget *i=item->widget();
            if(i)
            {
            m_Layout->removeWidget(i);
            delete i;
            }
        }
    }
    for(int k = 2; k < 4; ++k)
    {
        for (int j = 0; j < 4; ++j)
        {
            QLayoutItem *item=m_Layout->itemAtPosition(k + 2,j);
            QWidget *i=item->widget();
            if(i)
            {
            m_Layout->removeWidget(i);
            delete i;
            }
        }
    }
    m_Layout->addWidget(createButton("CE"), 1, 8);
    QString aButtons[4][9] = {
        {"sinh", "sin", "exp", "x^2", "7", "8", "9", "/", "sqrt"},
        {"cosh", "cos", "ln", "x^3", "4", "5", "6", "*", "1/x"},
        {"tanh", "tan", "log", "x^y", "1", "2", "3", "-", "1/x"},
        {"n!", "pi", "x^(1/3)", "x^(1/y)", "0", ".", "+", "="}
    };
    //Layout setup
    for (int i = 0; i < 2; ++i) {
       for (int j = 0; j < 9; ++j) {
           m_Layout->addWidget(createButton(aButtons[i][j]), i + 2, j);
       }
    }
    for (int i = 2; i < 4; ++i) {
       for (int j = 0; j < 8; ++j) {
           m_Layout->addWidget(createButton(aButtons[i][j]), i + 2, j);
       }
    }
    setFixedSize(600, 370);
    setWindowTitle("Калькулятор(Инженерный)");
}



void Calculator::calculateBinary()
{
     double dOperand2 = m_stk.pop().toDouble();
     QString strOperation = m_stk.pop();
     double dOperand1 = m_stk.pop().toDouble();
     double dResult = 0;
     if (strOperation == "+") {
     dResult = dOperand1 + dOperand2;
     }
     if (strOperation == "-") {
        dResult = dOperand1 - dOperand2;
     }
     if (strOperation == "/") {
        dResult = dOperand1 / dOperand2;
     }
     if (strOperation == "*") {
        dResult = dOperand1 * dOperand2;
     }
     if (strOperation == "x^y") {
        dResult = pow(dOperand1, dOperand2);
     }
     if (strOperation == "x^(1/y)") {
        dResult = pow(dOperand1, 1/dOperand2);
     }
     m_plcd->display(dResult);
}

long factorial(int number)
{
    if(number<=1)
        return 1;
    else
        return number*factorial(number-1);
}

void Calculator::calculateUnary()
{
    QString strOperation = m_stk.pop();
    double dOperand = m_stk.pop().toDouble();
    double dResult = 1;
    if (strOperation == "sqrt") {
        dResult = sqrt(dOperand);
    }
    if (strOperation == "1/x") {
        dResult = 1/dOperand;
    }
    if (strOperation == "sinh") {
        dResult = sinh(dOperand);
    }
    if (strOperation == "sin") {
        dResult = sin(dOperand);
    }
    if (strOperation == "exp") {
        dResult = exp(dOperand);
    }
    if (strOperation == "x^2") {
        dResult = dOperand*dOperand;
    }
    if (strOperation == "cosh") {
        dResult = cosh(dOperand);
    }
    if (strOperation == "cos") {
        dResult = cos(dOperand);
    }
    if (strOperation == "ln") {
        dResult = log(dOperand);
    }
    if (strOperation == "x^3") {
        dResult = pow(dOperand, 3);
    }
    if (strOperation == "tanh") {
        dResult = tanh(dOperand);
    }
    if (strOperation == "tan") {
        dResult = tan(dOperand);
    }
    if (strOperation == "log") {
        dResult = log10(dOperand);
    }
    if (strOperation == "n!") {
        dResult = factorial(dOperand);
    }
    if (strOperation == "x^(1/3)") {
        dResult = pow(dOperand, 1/3);
    }
    m_plcd->display(dResult);
}

void Calculator::slotButtonClicked()
{
    QString str = ((QPushButton*)sender())->text();
    if (str == "CE") {
        m_stk.clear();
        m_strDisplay = "";
        m_plcd->display("0");
        return;
    }
    if (str == "pi") {
        m_strDisplay = "";
        m_plcd->display(M_PI);
        return;
    }
    if (str.contains(QRegExp("[0-9]")) && (!str.contains(QRegExp("[/^]"))))
    {
        m_strDisplay += str;
        m_plcd->display(m_strDisplay.toDouble());
    }
     else if (str == ".") {
        if((!m_strDisplay.contains(".")) && (m_strDisplay.contains(QRegExp("[0-9]"))))
        {
            m_strDisplay += str;
            m_plcd->display(m_strDisplay);
        }
    }
     else if((str.contains(QRegExp("[+//-*=y]")) || (str == "/")))
    {
         if (m_stk.count() >= 2)
         {
             m_stk.push(QString().setNum(m_plcd->value()));
             calculateBinary();
             m_stk.clear();
             m_strDisplay = "";
             m_stk.push(QString().setNum(m_plcd->value()));
             if (str != "=")
             {
                m_stk.push(str);
             }
         }
         else
         {
             m_stk.push(QString().setNum(m_plcd->value()));
             m_stk.push (str);
             m_strDisplay = "";
             m_plcd->display("0");
         }
    }
    else
    {
        if (m_stk.count() >= 2)
        {
            m_stk.push(QString().setNum(m_plcd->value()));
            calculateBinary();
            m_stk.clear();
            m_strDisplay = "";
            m_stk.push(QString().setNum(m_plcd->value()));
            if (str != "=")
            {
               m_stk.push(str);
            }
        }
        else
        {
            m_stk.push(QString().setNum(m_plcd->value()));
            m_stk.push (str);
            calculateUnary();
            m_strDisplay = "";
        }
    }
}

void Calculator::radioButton1Clicked()
{
    CommonCalculator();
}

void Calculator::radioButton2Clicked()
{
    EngineerCalculator();
}


