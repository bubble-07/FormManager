#include "FileSelector.h"

FileSelector::FileSelector(QObject* parent) :QObject(parent) {
    return;
}
FileSelector::~FileSelector() {
    return;
}

void FileSelector::select() {
    QString fileTest = QFileDialog::getOpenFileName(NULL, 
        "Open Database", "C://", "Form Files (*.csv *.form)");
    if (fileTest == QString("")) {
        return; //the user didn't actually select a file
    }
    QFile* newFile = new QFile(fileTest);
    newFile->open(QIODevice::ReadOnly);
    CsvReader* newReader = new CsvReader(newFile);
    emit fileChanged(newReader);

    return;
}

