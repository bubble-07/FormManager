#include "addDialog.h"

AddDialog::AddDialog() :QDialog()
{
    this->layout = new QVBoxLayout;
    this->test = new NumberField();
    this->test2 = new BoolField();
    this->test3 = new AbstractEntry(new StringField(), new QString("hi"));
    this->layout->addWidget(this->test);
    this->layout->addWidget(this->test2);
    this->layout->addWidget(this->test3);
    this->setLayout(this->layout);
    this->setModal(true);

    return;
}
