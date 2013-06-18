#include "mainTable.h"

MainTable::MainTable(QWidget *parent, MainTableModel* model) 
    :QTableView(parent)
{
    this->setModel(model);
    return;
}

void MainTable::toggleHidden(int col)
{
    this->setColumnHidden(col, !this->isColumnHidden(col));
}
