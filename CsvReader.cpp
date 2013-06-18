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

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

QString CsvReader::get(int row, int column) {
    return QString(this->parsedFile[row][column].c_str());
}
void CsvReader::set(int row, int column, std::string val) {
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

void CsvReader::addRow() {
    std::vector<std::string> tmp;
    this->parsedFile.push_back(tmp);
    return;
}
void CsvReader::addToRow(int row, std::string val) {
    this->parsedFile[row].push_back(val);
    return;
}
void CsvReader::addRow(std::vector<std::string> init) {
    this->parsedFile.push_back(init);
    return;
}

size_t CsvReader::getNumRows() {
    return this->parsedFile.size();
}
