#include <vector>
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
    void saveFileNoClose();
    void set(int row, int column, std::string val);
    void addRow();
    void addRow(std::vector<std::string> init);
    std::vector<std::string> getRow(int row);
    void addToRow(int row, std::string val);
    void deleteRow(int row);
    void deleteRows(int begin, int end);
    void deleteAll();
    
    private:
    QFile* mainFile;
    void loadFile();
    std::string removeSpacesAfterCommas(std::string in);
    std::vector<std::vector<std::string> > parsedFile;
};

#endif
