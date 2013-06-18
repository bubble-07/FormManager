#include "AbstractEntry.h"


AbstractEntry::AbstractEntry(QWidget *parent) : QWidget(parent) {}


AbstractEntry::AbstractEntry(StringField* test, QString* label, 
                             QWidget *parent) 
    : QWidget(parent)
{
    this->optString = test;
    this->displayString = *label;
    this->type = AbstractEntry::STRING;
    this->layout = new QHBoxLayout();

    this->label = new QLabel(this->displayString);
    this->layout->addWidget(this->label);
    this->layout->addWidget(this->optString);

    this->setLayout(this->layout);
}
AbstractEntry::AbstractEntry(CsvLoc label, CsvLoc data, 
                             QWidget *parent) 
    : QWidget(parent)
{
    this->displayString = label.get();

    CsvLoc typeLoc = label;
    typeLoc.advance(0,1);
    QString type = typeLoc.get();
    
    optString = new StringField(data.get());


    this->type = AbstractEntry::STRING;
    this->layout = new QHBoxLayout();

    this->label = new QLabel(this->displayString);
    this->layout->addWidget(this->label);
    this->layout->addWidget(this->optString);

    this->setLayout(this->layout);
}
