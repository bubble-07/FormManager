#include "BundleReader.h"

BundleReader::BundleReader(CsvReader* in) {
    this->originFile = in;
    this->contentsDir = new QTemporaryDir();
    return;
}
QString BundleReader::path() {
    return this->contentsDir->path();
}
void BundleReader::changeOrigin(CsvReader* new_origin) {
    this->originFile = new_origin;
    return;
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

QFile* BundleReader::getNamedFile(QString in) {
    QDir bundleDir(this->path());
    QStringList filters;
    filters << in;

    QFileInfoList matchingFiles = bundleDir.entryInfoList(filters);

    if (matchingFiles.size() > 1 or matchingFiles.size() == 0) {
        return NULL;
    }
    return new QFile(matchingFiles[0].filePath());
}

QFile* BundleReader::getFormatFile() {
    return this->getNamedFile(QString("format.csv"));
}
QFile* BundleReader::getDataFile() {
    return this->getNamedFile(QString("data.csv"));
}

void BundleReader::pack() {
    QDir bundleDir(this->path());
    QStringList filters;
    filters << "*.csv";

    originFile->deleteAll();
    
    QFileInfoList containedFiles = bundleDir.entryInfoList(filters);

    for (size_t i = 0; i < containedFiles.size(); i++) {
        QFile tmpFile(containedFiles[i].filePath());
        tmpFile.open(QFile::ReadOnly | QFile::Text );
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

    this->originFile->saveFile();
    return;
}
void BundleReader::extract() {

    QDir bundleDir(this->path());

    for (size_t i = 0; i < originFile->getNumRows(); i++) {
        std::vector<std::string> header = originFile->getRow(i);
        QString filename = QString(header[0].c_str());
        size_t numRows = atoi(header[1].c_str());

        QFile currentQFile(this->path() + "/" + filename);
        currentQFile.open(QIODevice::ReadWrite);

        CsvReader currentFile(&currentQFile);

        for (size_t n = 0; n < numRows; n++) {
            i++;
            currentFile.addRow(originFile->getRow(i));
        }
        currentFile.saveFile();
        currentQFile.close();
    }
    return;
}

