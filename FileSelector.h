#include <QWidget>
#include <QFileDialog>
#include "CsvReader.h"
#ifndef FILESELECTOR_DEFINED
#define FILESELECTOR_DEFINED
class FileSelector : public QObject
{
    Q_OBJECT

    public:
    FileSelector(QObject* parent = 0);
    ~FileSelector();
    public slots:
    void select();
    
    signals:
    void fileChanged(CsvReader* newFile);
};

#endif
