#include <QWidget>
#include <QSignalMapper>
#include <QAction>
#include <QVBoxLayout>
#include <QTableView>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <vector>
#include "CsvReader.h"
#include "CsvLoc.h"
#include "MainTableModel.h"
#include "MainTable.h"
#include "visibilityMenu.h"
#include "addDialog.h"
#include "EntryFields/NumberField.h"


#ifndef MAINWINDOW_DEFINED
#define MAINWINDOW_DEFINED

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow() {};
};
#endif
