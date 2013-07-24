#include <string>
#include <vector>
#include <sstream>
#include <QTextStream>
#include "CsvReader.h"

CsvReader::CsvReader(QFile* in) {
    mainFile = in;
    this->loadFile();
    return;
}
//this is used for when a file needs to be used without loading it
CsvReader::CsvReader(QFile* in, int PLACEHOLDER) {
    mainFile = in;
    return;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

QString CsvReader::get(size_t row, size_t column) {
    if (row > this->getNumRows()) {
        return QString("");
    }
    if (column > this->parsedFile[row].size() - 1) {
        return QString("");
    }
    return QString(this->parsedFile[row][column].c_str());
}
void CsvReader::set(size_t row, size_t column, std::string val) {
    this->parsedFile[row][column] = val;
}

std::string CsvReader::removeSpacesAfterCommas(std::string in) {
    size_t n = 0;
    for (size_t i = 0; i < in.size(); i++, n++) {
        in[n] = in[i];
        if (in[i] == ',' and i + 1 < in.size()) {
            if (in[i+1] == ' ') {
                i++;
            }
        }
    }
    in.resize(n);
    return in;
}

void CsvReader::loadFile() {
    mainFile->reset();
    QTextStream input(mainFile);
    for (; !input.atEnd();) {
        std::string line = input.readLine().toStdString();
        line = this->removeSpacesAfterCommas(line);
        std::vector<std::string> parsed_line = split(line, ',');
        this->parsedFile.push_back(parsed_line);
    }
    return;
}

void CsvReader::saveFile() {
    mainFile->close();
    mainFile->open(QFile::Truncate | QFile::Text | QFile::WriteOnly);
    QTextStream output(mainFile);

    for (size_t i = 0; i < this->getNumRows(); i++) {
        for (size_t j = 0; j < this->parsedFile[i].size(); j++) {

            output << this->get(i, j);

            if (j < (this->parsedFile[i].size() - 1)) {
                output << ", ";
            }
        }
        output << endl;
    }
}

void CsvReader::saveFileNoClose() {
    QTextStream output(mainFile);

    for (size_t i = 0; i < this->getNumRows(); i++) {
        for (size_t j = 0; j < this->parsedFile[i].size(); j++) {

            output << this->get(i, j);

            if (j < (this->parsedFile[i].size() - 1)) {
                output << ", ";
            }
        }
        output << endl;
    }
}

void CsvReader::addRow() {
    std::vector<std::string> tmp;
    this->parsedFile.push_back(tmp);
    return;
}
void CsvReader::addToRow(size_t row, std::string val) {
    this->parsedFile[row].push_back(val);
    return;
}
void CsvReader::addRow(std::vector<std::string> init) {
    this->parsedFile.push_back(init);
    return;
}
void CsvReader::deleteRow(size_t row) {
    if (row < parsedFile.size())
        this->parsedFile.erase(this->parsedFile.begin() + row); 
    return;
}
void CsvReader::deleteAll() {
    if (this->parsedFile.size() > 1) {
        this->deleteRows(0, this->parsedFile.size()-1);
    }
    return;
}
void CsvReader::deleteRows(size_t begin, size_t end) {
    if (end < parsedFile.size())
        this->parsedFile.erase(this->parsedFile.begin() + begin,
                               this->parsedFile.begin() + end + 1); 
    return;
}
size_t CsvReader::getNumRows() {
    return this->parsedFile.size();
}
std::vector<std::string> CsvReader::getRow(size_t row) {
    return parsedFile[row];
}
