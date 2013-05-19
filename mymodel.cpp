#include "mymodel.h"

MyModel::MyModel(QObject *parent, QFile* fFile)
    :QAbstractTableModel(parent)
{
   this->formatFile = fFile;
   this->formatFile->open(QIODevice::ReadOnly | QIODevice::Text);
   this->rRowCount = 2;
   this->rColCount = 2;
   return;
}

int MyModel::rowCount(const QModelIndex & /*parent*/) const
{
    return rRowCount;
}

int MyModel::columnCount(const QModelIndex &) const
{
    return rColCount;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        /*return QString("Row%1, Column %2")
                .arg(index.row() + 1)
                .arg(index.column() + 1); */
        CsvReader tmp = CsvReader(formatFile);
        return tmp.get(index.row(), index.column());

    }
    return QVariant();
}

