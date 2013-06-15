#include <QApplication>
#include <QAbstractTableModel>
#include <QFile>
#include "CsvReader.h"

#ifndef MYMODEL_DEFINED
#define MYMODEL_DEFINED

class MyModel : public QAbstractTableModel
{
    Q_OBJECT

    public:
    MyModel(QObject *parent, CsvReader* in);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation o, int role=Qt::DisplayRole) const;

    private:
    int rRowCount;
    int rColCount;
    CsvReader* formatFile;
};

#endif
