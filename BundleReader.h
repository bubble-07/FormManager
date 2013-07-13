#include "CsvReader.h"
#include <QTemporaryDir>
#include <sstream>
#include <iostream>
#include <QTemporaryFile>

#ifndef BUNDLEREADER_DEFINED
#define BUNDLEREADER_DEFINED

class BundleReader
{
    public:
    BundleReader(QFile* in);
    void extract();
    void addFile(QFile* toAdd);
    void pack(QString destination);
    QString path();

    private:
    QFile* originFile;
    QTemporaryDir* contentsDir;
};
#endif
