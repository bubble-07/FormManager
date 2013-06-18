#include "MainTableModel.h"

MainTableModel::MainTableModel(QObject *parent, 
                               CsvReader* format, CsvReader* data)
    :QAbstractTableModel(parent)
{
   this->formatFile = format;
   this->dataFile = data;
   this->rRowCount = this->dataFile->getNumRows();
   this->rColCount = this->formatFile->getNumRows();
   return;
}

int MainTableModel::rowCount(const QModelIndex & /*parent*/) const
{
    return rRowCount;
}

int MainTableModel::columnCount(const QModelIndex &) const
{
    return rColCount;
}

QVariant MainTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        return this->dataFile->get(index.row(), index.column());
        return QString("Row%1, Column %2")
                .arg(index.row() + 1)
                .arg(index.column() + 1);
    }
    return QVariant();
}
QVariant MainTableModel::headerData(int s, Qt::Orientation o, int role) const {
    if (role == Qt::DisplayRole) {
        if (o==Qt::Horizontal) {
            return formatFile->get(s, 0);
        }
        else {
            return QString("%1").arg(s+ 1);
        }
    }
    return QVariant();
}




