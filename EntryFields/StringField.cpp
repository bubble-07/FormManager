#include "StringField.h"

StringField::StringField(const QString& contents, QWidget *parent)
    :QLineEdit(contents, parent)
{
}
QString StringField::get() {
    return this->text();
}
