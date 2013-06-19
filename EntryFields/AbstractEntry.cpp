#include "AbstractEntry.h"


//AbstractEntry::AbstractEntry(QWidget *parent) : QWidget(parent) {}

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

    this->dataLoc = data;

    if (type == "String") {
        optString = new StringField(data.get());
        this->type = AbstractEntry::STRING;
        this->layout->addWidget(this->optString);
    }
    if (type == "Number") {
        optNumber = new NumberField(data.get());
        this->type = AbstractEntry::NUMBER;
        this->layout->addWidget(this->optNumber);
    }
    if (type == "Bool") {
        optBool = new BoolField(data.get());
        this->type = AbstractEntry::BOOL;
        this->layout->addWidget(this->optBool);
    }

    this->setLayout(this->layout);
}

void AbstractEntry::save() {
    if (this->type == AbstractEntry::BOOL) {
        this->dataLoc.set(this->optBool->get());
    }
    if (this->type == AbstractEntry::STRING) {
        this->dataLoc.set(this->optString->get());
    }
    if (this->type == AbstractEntry::NUMBER) {
        this->dataLoc.set(this->optNumber->get());
    }
    return;
}

void AbstractEntry::setAsFocus() {
    this->setFocus(Qt::TabFocusReason);
    if (this->type == AbstractEntry::STRING) {
        this->optString->selectAll();
        this->optString->setFocus(Qt::TabFocusReason);
    }
    if (this->type == AbstractEntry::NUMBER) {
        this->optNumber->selectAll();
        this->optNumber->setFocus(Qt::TabFocusReason);
    }
    if (this->type == AbstractEntry::BOOL) {
        this->optBool->selectAll();
        this->optBool->setFocus(Qt::TabFocusReason);
    }
    
}

AbstractEntry::~AbstractEntry() {
    if (this->type == AbstractEntry::BOOL) {
        delete optBool;
    }
    if (this->type == AbstractEntry::NUMBER) {
        delete optNumber;
    }
    if (this->type == AbstractEntry::STRING) {
        delete optString;
    }

    delete layout;
    delete label;
}
