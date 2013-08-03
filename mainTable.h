#include <QTableView>
#include "MainTableModel.h"

#ifndef MAINTABLE_DEFINED
#define MAINTABLE_DEFINED

class MainTable : public QTableView
{
    Q_OBJECT

    public:
    MainTable(QWidget *parent, MainTableModel* model);
    void changeModel(MainTableModel* model);

    private:
    MainTableModel* model;
    
    public slots:
    void toggleHidden(int col);
    void addRow();
    void editSelected();
    void deleteSelected();
};

#endif
