#include <QTableView>
#include "mymodel.h"
class MainTable : public QTableView
{
    Q_OBJECT

    public:
    MainTable(QWidget *parent, MyModel* model);
    
    public slots:
    void toggleHidden(int col);
};




