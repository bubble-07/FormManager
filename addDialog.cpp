#include "addDialog.h"

AddDialog::AddDialog() :QDialog()
{
    this->layout = new QVBoxLayout;
    this->test = new NumberField();
    this->layout->addWidget(this->test);
    this->setLayout(this->layout);
    this->setModal(true);

    return;
}
