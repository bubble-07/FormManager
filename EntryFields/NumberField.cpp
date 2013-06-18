#include "NumberField.h"

NumberField::NumberField(const QString& init, QWidget *parent)
    :QLineEdit(init, parent)
{
    this->validator = new QDoubleValidator();
    this->setValidator(this->validator);
}
