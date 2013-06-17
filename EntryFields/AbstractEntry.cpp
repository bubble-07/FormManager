#include "AbstractEntry.h"


AbstractEntry::AbstractEntry(QWidget *parent) : QWidget(parent) {}

//AbstractEntry::~AbstractEntry() {}


AbstractEntry::AbstractEntry(StringField* test, QString* label, 
                             QWidget *parent) 
    : QWidget(parent)
{
    this->optString = test;
    this->displayString = label;
    this->type = AbstractEntry::STRING;
    this->layout = new QHBoxLayout();

    this->label = new QLabel(*this->displayString);
    this->layout->addWidget(this->label);
    this->layout->addWidget(this->optString);

    this->setLayout(this->layout);
}
