#include "addDialog.h"

AddDialog::AddDialog(CsvReader* labelFile, CsvLoc* dataLoc) :QDialog()
{
    this->layout = new QVBoxLayout;
    
    CsvLoc* labelLoc = new CsvLoc(labelFile, 0, 0);

    for (size_t i = 0; i < labelFile->getNumRows(); i++) {

        this->entries.push_back(new AbstractEntry(*labelLoc, *dataLoc));

        this->layout->addWidget(this->entries[this->entries.size() - 1]);

        dataLoc->advance(0, 1);
        labelLoc->advance(1, 0);
    }

    this->setLayout(this->layout);
    this->setModal(true);

    return;
}
