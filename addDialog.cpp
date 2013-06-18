#include "addDialog.h"

AddDialog::AddDialog(CsvReader* labelFile, CsvLoc* dataLoc) :QDialog()
{
    this->viewLayout = new QVBoxLayout;
    this->viewLayout->setSpacing(0);
    
    CsvLoc* labelLoc = new CsvLoc(labelFile, 0, 0);

    for (size_t i = 0; i < labelFile->getNumRows(); i++) {

        this->entries.push_back(new AbstractEntry(*labelLoc, *dataLoc));

        this->viewLayout->addWidget(this->entries[this->entries.size()-1]);

        dataLoc->advance(0, 1);
        labelLoc->advance(1, 0);
    }

    this->displayArea = new QWidget();
    this->displayArea->setLayout(this->viewLayout);
    this->scrollArea = new QScrollArea;
    scrollArea->setWidget(displayArea);
    this->windowLayout = new QVBoxLayout;
    this->windowLayout->addWidget(scrollArea);
    this->setLayout(windowLayout);
    
    this->setModal(true);

    return;
}
