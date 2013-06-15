#include <string>
#include <vector>
#include <sstream>
#include "CsvReader.h"

CsvReader::CsvReader(QFile* in) {
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

QString CsvReader::get(int row, int column) {
    mainFile->reset();
    for (int i = 0; i < row; i++) {
        char buf[1024];
        mainFile->readLine(buf, sizeof(buf));
    }
    char tmpresult[1024];
    mainFile->readLine(tmpresult, sizeof(tmpresult));
    std::string line(tmpresult);
    
    std::vector<std::string> parsedline = split(line, ',');

    return QString(parsedline[column].c_str());
}
int CsvReader::getNumRows() {
    mainFile->reset();
    int count;
    for (count = 0; !mainFile->atEnd(); count++) {
        char buf[1024];
        mainFile->readLine(buf, sizeof(buf));
    }
    return count;
}
