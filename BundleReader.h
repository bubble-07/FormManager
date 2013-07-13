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
    BundleReader(CsvReader* in);
    //void extract();
    void addFile(QFile* toAdd);
    void pack(QString destination);
    QString path();

    private:
    CsvReader* originFile;
    QTemporaryDir* contentsDir;
};
#endif
