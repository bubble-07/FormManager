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

void MainTableModel::addRow() {
    this->beginInsertRows(QModelIndex(), rRowCount, rRowCount);

    std::vector<std::string> tmp(rColCount, "");
    this->dataFile->addRow(tmp);
    this->rRowCount += 1;

    this->endInsertRows();
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




