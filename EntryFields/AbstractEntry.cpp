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

    this->layout = new QHBoxLayout();

    this->label = new QLabel(this->displayString);
    this->layout->addWidget(this->label);


    CsvLoc typeLoc = label;
    typeLoc.advance(0,1);
    QString type = typeLoc.get();

    if (type == " String") {
        optString = new StringField(data.get());
        this->type = AbstractEntry::STRING;
        this->layout->addWidget(this->optString);
    }
    if (type == " Number") {
        optNumber = new NumberField(data.get());
        this->type = AbstractEntry::NUMBER;
        this->layout->addWidget(this->optNumber);
    }
    if (type == " Bool") {
        optBool = new BoolField(data.get());
        this->type = AbstractEntry::BOOL;
        this->layout->addWidget(this->optBool);
    }

    this->setLayout(this->layout);
}
