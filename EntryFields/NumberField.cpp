#include "NumberField.h"

NumberField::NumberField(QWidget *parent)
    :QLineEdit(parent)
{
    this->validator = new QDoubleValidator();
    this->setValidator(this->validator);
}
