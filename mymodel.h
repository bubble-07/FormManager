#include <QApplication>
#include <QAbstractTableModel>
#include <QFile>
#include "csvfile.h"

class MyModel : public QAbstractTableModel
{
    Q_OBJECT

    public:
    MyModel(QObject *parent, QFile* fFile);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation o, int role=Qt::DisplayRole) const;

    private:
    int rRowCount;
    int rColCount;
    QFile* formatFile;
};
