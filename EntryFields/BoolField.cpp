#include "BoolField.h"

BoolField::BoolField(const QString& init, QWidget *parent)
    :QSpinBox(parent)
{
    this->setMinimum(0);
    this->setMaximum(1);
    this->setValue(this->valueFromText(init)); 
    this->setWrapping(true);
}

int BoolField::valueFromText(const QString & text) const {
    if (text == "y" or text == "Y" or text == "yes" or text == "Yes") {
        return 1;
    }
    if (text == "n" or text == "N" or text == "no" or text == "No") {
        return 0;
    }
    return 0;
}

QString BoolField::textFromValue(int in) const {
    if (in == 1) {
        return QString("Yes");
    }
    return QString("No");
}

QValidator::State BoolField::validate(QString & text, int & pos) const {
    return QValidator::Acceptable;
}
