#include <QFile>

#ifndef CSVREADER_DEFINED
#define CSVREADER_DEFINED

class CsvReader
{
    public:
    CsvReader(QFile* in);
    QString get(int row, int column);
    int getNumRows();
    
    private:
    QFile* mainFile;
};

#endif
