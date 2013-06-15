#include "StringField.h"

StringField::StringField(QWidget *parent)
    :QLineEdit(parent)
{
    this->validator = new QDoubleValidator();
    this->setValidator(this->validator);
}
