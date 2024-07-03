#include "styles.h"
//fa464e


QString Styles::getAccountWidgetStyle()
{
    return "QWidget#accountWindow {"
           "    background-image: url(:/Assets/bg.png);"
           "}";
}

QString Styles::getLabelText()
{
    return "QLabel {"
           "    font-family: 'Roboto Medium';"
           "    font-weight: bold;"
           "    font-size: 12px;"
           "    color: #ffffff;"
           "}";
}

QString Styles::getScrollAreaStyle()
{
    return "QScrollArea {"
           "    border: 2px solid #fa464e;"
           "    background-image: url(:/Assets/bg.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center;"
           "}"
           "QScrollArea QWidget {"
           "    background-color: transparent;"
           "}";
}

QString Styles::getScrollAreaBoardStyle()
{
    return "QScrollArea {"
           "    border: 2px solid #ffffff;"
           "    border-radius: 4px;"
           "    background-image: url(:/Assets/bg.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center;"
           "}"
           "QScrollArea QWidget {"
           "    background-color: transparent;"
           "}";
}

QString Styles::getTextBrowserStyle()
{

    return "QTextBrowser {"
           "    border: 2px solid #fa464e;"
           "    font-family: 'Roboto Medium';"
           "    font-weight: bold;"
           "    font-size: 12px;"
           "    color: #ffffff;"
           "}";

}

QString Styles::getListWidgetStyle()
{
    return "QWidget#listNedoRello {"
           "    background-image: url(:/Assets/bg.png);"
           "    border: 2px solid #ffffff;"
           "    border-radius: 4px;"
           "}";
}

QString Styles::getDateTimeEditStyle()
{
    return "QDateTimeEdit {"
            "   border: 2px solid #fa464e;"
            "   border-radius: 4px;"
            "   padding: 4px 8px;"
            "   font-size: 14px;"
            "   background-color: transparent;"
            "   background-image: url(:/Assets/bg.png);"
            "   background-repeat: no-repeat;"
            "   background-position: center;"
            "   color: white;"
            "   font-family: 'Roboto Medium';"
            "}"
            "QDateTimeEdit::up-button, QDateTimeEdit::down-button {"
            "   background-color: transparent;"
            "   border: none;"
            "   border-radius: 4px;"
            "   width: 16px;"
            "   height: 16px;"
            "}"
            "QDateTimeEdit::up-arrow {"
            "   image: url(:/Assets/arrowUP.png);"
            "}"
            "QDateTimeEdit::down-arrow {"
            "image: url(:/Assets/arrowDown.png);"
            "}"
            "QDateTimeEdit, QDateTimeEdit * {"
            "   color: white;"
            "}";

}

QString Styles::getNormalStyle()
{
    return "QWidget#cardNedoRello {"
           "    background-color: transparent;"
           "    background-image: url(:/Assets/bg.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center;"
           "    border: 4px solid #808080;"
           "    border-radius: 8px;"
           "}";
}

QString Styles::getAcceptStyle()
{
    return "QWidget#cardNedoRello {"
           "    background-color: transparent;"
           "    background-image: url(:/Assets/bg.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center;"
           "    border: 4px solid #00FF00;"
           "    border-radius: 8px;"
           "}";
}

QString Styles::getNotCompletedStyle()
{
    return "QWidget#cardNedoRello {"
           "    background-color: transparent;"
           "    background-image: url(:/Assets/bg.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center;"
           "    border: 4px solid #fa464e;"
           "    border-radius: 8px;"
           "}";
}

QString Styles::getEditStyle()
{
    return "QLineEdit, QTextEdit {"
           "    background-image: url(:/Assets/bg.png);"
           "    border: 2px solid #fa464e;"
           "    border-radius: 4px;"
           "    font-family: 'Roboto Medium';"
           "    font-size: 12px;"
           "    color: #ffffff;"
           "}"
           "QLineEdit:focus, QTextEdit:focus {"
           "    border: 2px solid #00ff00;"
           "}";
}

QString Styles::getButtonStyle()
{
    return "QPushButton {"
           "    background-image: url(:/Assets/bg.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center;"
           "    border: 2px solid #fa464e;"
           "    border-radius: 5px;"
           "    padding: 10px 20px;"
           "    color: white;"
           "    font-family: 'Roboto Medium';"
           "    font-size: 12px;"
           "    color: #ffffff;"
           "    font-weight: bold;"
           "}"
           "QPushButton:pressed {"
           "    border: 2px solid #00ff00;"
           "}";
}




