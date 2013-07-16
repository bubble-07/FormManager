#include "FileSelector.h"

FileSelector::FileSelector(QObject* parent) :QObject(parent) {
    1 + 2;
    return;
}
FileSelector::~FileSelector() {
    return;
}

void FileSelector::select() {
    QString fileTest = QFileDialog::getOpenFileName(NULL, 
        "Open Database", "C://", "Form Files (*.csv *.form)");
    return;
}

