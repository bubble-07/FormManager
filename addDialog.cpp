#include "addDialog.h"

AddDialog::AddDialog(CsvReader* labelFile, CsvLoc* dataLoc, int entryFocus)
        :QDialog()
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

    this->doneButton = new QPushButton("&Save And Finish");
    this->viewLayout->addWidget(doneButton);
    QObject::connect(doneButton, SIGNAL(released()), 
                     this, SLOT(saveAllAndExit()));

    this->displayArea = new QWidget();
    this->displayArea->setLayout(this->viewLayout);

    this->scrollArea = new QScrollArea;
    scrollArea->setWidget(displayArea);
    this->windowLayout = new QVBoxLayout;
    this->windowLayout->addWidget(scrollArea);
    this->setLayout(windowLayout);
    
    this->setModal(true);

    if (entryFocus != -1) {
        this->setFieldFocus(entryFocus);
    }

    return;
}
void AddDialog::saveAllAndExit() {
    for (size_t i = 0; i < this->entries.size(); i++) {
        this->entries[i]->save();
    }
    /*ToDo: dealloc all entries and call destructor, proper*/
    this->done(0);
}

//true if the user is warned about closing
void AddDialog::close(bool warn) {
    if (warn == true) {
        QMessageBox quitBox;
        quitBox.setText("You did not hit the save button.");
        quitBox.setInformativeText("Do you want to save changes?");
        quitBox.setStandardButtons(QMessageBox::Save | 
                                   QMessageBox::Discard);
        quitBox.setDefaultButton(QMessageBox::Save);

        int ret = quitBox.exec();
        if (ret == QMessageBox::Save) {
            this->saveAllAndExit();
        }
    }
    else {
        this->saveAllAndExit();
    }
    return;
}

void AddDialog::setFieldFocus(int pos) {
    if (this->entries.size() > pos) {
        this->entries[pos]->setAsFocus();
    }
    return;
}

//what happens when the window is closed with the "close" button
void AddDialog::closeEvent(QCloseEvent *event) {
   close(true);
}

//what happens when the "Esc" key is pressed
void AddDialog::reject() {
    close(true);
}

AddDialog::~AddDialog() {
    for (size_t i = 0; i < entries.size(); i++) {
        delete entries[i];
    }
    delete viewLayout;
    delete displayArea;
    delete scrollArea;
    delete windowLayout;
}
