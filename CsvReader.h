#include <vector>
#include <QFile>

#ifndef CSVREADER_DEFINED
#define CSVREADER_DEFINED

class CsvReader
{
    public:
    CsvReader(QFile* in);
    CsvReader(QFile* in, int PLACEHOLDER);
    QString get(size_t row, size_t column);
    size_t getNumRows();
    void saveFile();
    void saveFileNoClose();
    void set(size_t row, size_t column, std::string val);
    void addRow();
    void addRow(std::vector<std::string> init);
    std::vector<std::string> getRow(size_t row);
    void addToRow(size_t row, std::string val);
    void deleteRow(size_t row);
    void deleteRows(size_t begin, size_t end);
    void deleteAll();
    
    private:
    QFile* mainFile;
    void loadFile();
    std::string removeSpacesAfterCommas(std::string in);
    std::vector<std::vector<std::string> > parsedFile;
};

#endif
