#include <QFile>

#ifndef CSVREADER_DEFINED
#define CSVREADER_DEFINED

class CsvReader
{
    public:
    CsvReader(QFile* in);
    QString get(int row, int column);
    size_t getNumRows();
    void saveFile();
    void set(int row, int column, std::string val);
    
    private:
    QFile* mainFile;
    void loadFile();
    std::vector<std::vector<std::string> > parsedFile;
};

#endif
