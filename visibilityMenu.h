#include <QMenu>
#include <QSignalMapper>
#include <QAction>
#include <stdlib.h>
#include "mainTable.h"

#ifndef VISIBILITYMENU_DEFINED
#define VISIBILITYMENU_DEFINED

class VisibilityMenu : public QMenu
{
    Q_OBJECT

    public:
    VisibilityMenu(QString name, CsvReader* file, MainTable* table);
    void changeFile(CsvReader* file);

    public slots:
    void hideAll();
    void showAll();

    private:
    CsvReader* formatFile;
    MainTable* table;
    QAction* showall;
    QAction* hideall;
    std::vector<QAction*> options;
    QSignalMapper* signalMapper;
    int menusize;
};
#endif
