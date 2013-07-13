#include "BundleReader.h"

BundleReader::BundleReader(CsvReader* in) {
    this->originFile = in;
    this->contentsDir = new QTemporaryDir();
    return;
}
QString BundleReader::path() {
    return this->contentsDir->path();
}

void BundleReader::addFile(QFile* toAdd) {
    QFileInfo tmpInfo(toAdd->fileName());
    toAdd->copy(this->contentsDir->path() + "/" + tmpInfo.fileName());
    return;
}

void printLine(std::vector<std::string> in) {
    for (size_t i = 0; i < in.size(); i++) {
        std::cout << in[i] << ", ";
    }
    std::cout << std::endl;
}

void BundleReader::pack(QString destination) {
    QDir bundleDir(this->path());
    QStringList filters;
    filters << "*.csv";

    originFile->deleteAll();
    
    QFileInfoList containedFiles = bundleDir.entryInfoList(filters);

    for (size_t i = 0; i < containedFiles.size(); i++) {
        QFile tmpFile(containedFiles[i].filePath());
        tmpFile.open(QIODevice::ReadOnly);
        CsvReader tmpReader(&tmpFile);

        /*add the header for each entry*/
        std::vector<std::string> header;
        header.push_back(containedFiles[i].fileName().toStdString());

        std::string numRows;
        {
            std::ostringstream tmpStream;
            tmpStream << tmpReader.getNumRows();
            numRows = tmpStream.str();
        }
        header.push_back(numRows);
        originFile->addRow(header);
        printLine(header);

        /*add the data from each entry*/
        for (size_t j = 0; j < tmpReader.getNumRows(); j++) {
            printLine(tmpReader.getRow(j));
            originFile->addRow(tmpReader.getRow(j));
        }
    }

    originFile->saveFile();
    return;
}
    /* 
void BundleReader::extract() {

    QDir bundleDir(this->path());

    QByteArray data = qUncompress(this->originFile->readAll());
    
    QTemporaryFile unpackingFile;
    unpackingFile.open();
    unpackingFile.write(data);
    
    CsvReader csvFile(&unpackingFile);
    
    for (size_t i = 0; i < csvFile.getNumRows(); i++) {
        std::vector<std::string> header = csvFile.getRow(i);
        QString filename = QString(header[0].c_str());
        size_t numRows = atoi(header[1].c_str());

        QFile currentQFile(this->path() + "/" + filename);
        currentQFile.open(QIODevice::ReadWrite);

        CsvReader currentFile(&currentQFile);

        for (size_t n = 0; n < numRows; n++) {
            i++;
            currentFile.addRow(csvFile.getRow(i));
        }
        currentFile.saveFile();
        currentQFile.close();
    }
    return;
} */

