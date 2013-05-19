#include <QFile>
class CsvReader
{
    public:
    CsvReader(QFile* in);
    QString get(int row, int column);
    
    private:
    QFile* mainFile;
};
