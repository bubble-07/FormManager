#include <QString>
#include "stdlib.h"
#include "CsvReader.h"

#ifndef CSVLOC_DEFINED
#define CSVLOC_DEFINED
class CsvLoc {
    public:
    CsvReader* reader;
    int row;
    int col;
    CsvLoc(CsvReader* reader, int row, int col);
    CsvLoc();
    QString get();
    void set(QString val);
    void advance(int rows, int cols);
};

#endif
