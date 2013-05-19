#include "csvfile.h"

CsvReader::CsvReader(QFile* in) {
    mainFile = in;
    return;
}

QString CsvReader::get(int row, int column) {
    mainFile->reset();
    for (int i = 0; i < row; i++) {
        char buf[1024];
        mainFile->readLine(buf, sizeof(buf));
    }
    char tmpresult[1024];
    mainFile->readLine(tmpresult, sizeof(tmpresult));
    return QString(tmpresult);
}
