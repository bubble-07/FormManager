#include <QFileDialog>
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
#include "BundleReader.h"
#include "FileSelector.h"
#include "EntryFields/NumberField.h"


#ifndef MAINWINDOW_DEFINED
#define MAINWINDOW_DEFINED

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow() {};
    void init();

    private:
    CsvReader* formatFile;
    CsvReader* dataFile;
    BundleReader* mainBundle;
    QToolBar* mainToolBar;
    FileSelector* mainSelector;
    
    MainTableModel* myModel;
    MainTable* table;

    QAction* openaction;
    QAction* editaction;
    QAction* deleteaction;
    QAction* addaction;

    QMenuBar menu;
    VisibilityMenu* showhide;

    QVBoxLayout* layout;
};
#endif
