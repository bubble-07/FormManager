#include "mainTable.h"

MainTable::MainTable(QWidget *parent, MainTableModel* model) 
    :QTableView(parent)
{
    this->model = model;
    this->setModel(model);
    return;
}

void MainTable::toggleHidden(int col)
{
    this->setColumnHidden(col, !this->isColumnHidden(col));
}
void MainTable::addRow() {
    this->model->addRow();
}
