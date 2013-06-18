#include <QApplication>
#include <QAbstractTableModel>
#include <QFile>
#include "CsvReader.h"

#ifndef MAINTABLEMODEL_DEFINED
#define MAINTABLEMODEL_DEFINED

class MainTableModel : public QAbstractTableModel
{
    Q_OBJECT

    public:
    MainTableModel(QObject *parent, CsvReader* format, CsvReader* data);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation o, int role=Qt::DisplayRole) const;
    void addRow();

    private:
    int rRowCount;
    int rColCount;
    CsvReader* formatFile;
    CsvReader* dataFile;
};

#endif
