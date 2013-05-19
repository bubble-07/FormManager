#include <QApplication>
#include <QAbstractTableModel>
#include <QFile>
#include "csvfile.h"

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
    public:
    MyModel(QObject *parent, QFile* fFile);
    QFile* formatFile;
    int rRowCount;
    int rColCount;
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};
