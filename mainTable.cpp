#include "mainTable.h"

MainTable::MainTable(QWidget *parent, MainTableModel* model) 
    :QTableView(parent)
{
    this->model = model;
    this->setModel(model);
    QObject::connect(this, SIGNAL(doubleClicked(const QModelIndex&)), 
                     this->model, SLOT(editCell(const QModelIndex&)));
    return;
}

void MainTable::toggleHidden(int col)
{
    this->setColumnHidden(col, !this->isColumnHidden(col));
}
void MainTable::addRow() {
    this->model->addRow();
}
void MainTable::editSelected() {
    QItemSelectionModel *select = this->selectionModel();
    QModelIndexList indexes = select->selectedIndexes();
    //yup, that's right, just edit the first one we find...
    if (indexes.size() > 0) {
        this->model->editCell(indexes[0]);
    }
    //else, do nothing -- can't edit nothing
    return;
}

void MainTable::deleteSelected() {
    QItemSelectionModel *select = this->selectionModel();
    QModelIndexList indexes = select->selectedIndexes();
    //yup, that's right, just delete the first row we find...
    if (indexes.size() > 0) {

        QMessageBox deleteBox;
        deleteBox.setText("Are you sure you want to delete the selection?");
        deleteBox.setStandardButtons(QMessageBox::Ok | 
                                   QMessageBox::Cancel);
        deleteBox.setDefaultButton(QMessageBox::Cancel);

        int ret = deleteBox.exec();
        if (ret == QMessageBox::Ok) {
            this->model->deleteRows(indexes[0], indexes[indexes.size()-1]);
        }
    }
    //else, do nothing -- can't delete nothing
    return;
}
