#include <string>
#include <vector>
#include <sstream>
#include "CsvReader.h"
#define MAX_LINE_WIDTH 1048576


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

void CsvReader::loadFile() {
    mainFile->reset();
    for (; !mainFile->atEnd();) {
        char buf[MAX_LINE_WIDTH];
        mainFile->readLine(buf, sizeof(buf));
        std::string line(buf);
        std::vector<std::string> parsed_line = split(line, ',');
        this->parsedFile.push_back(parsed_line);
    }
    return;
}

int CsvReader::getNumRows() {
    return this->parsedFile.size();
}
