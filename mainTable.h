#include <QTableView>
#include "mymodel.h"

#ifndef MAINTABLE_DEFINED
#define MAINTABLE_DEFINED

class MainTable : public QTableView
{
    Q_OBJECT

    public:
    MainTable(QWidget *parent, MyModel* model);
    
    public slots:
    void toggleHidden(int col);
};

#endif
