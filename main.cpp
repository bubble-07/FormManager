#include <QApplication>
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
#include "EntryFields/NumberField.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile* tmpformatFile = new QFile("c://formatTest.csv");
    tmpformatFile->open(QIODevice::ReadOnly);
    CsvReader* formatFile = new CsvReader(tmpformatFile);

    QFile* tmpdataFile = new QFile("c://dataTest.csv");
    tmpdataFile->open(QIODevice::ReadOnly);
    CsvReader* dataFile = new CsvReader(tmpdataFile);

    QFile* bundleTest = new QFile("c://siwwy.csv");
    bundleTest->open(QFile::Text | QFile::ReadWrite);
    CsvReader* bundleTestRead = new CsvReader(bundleTest);

    BundleReader bundle(bundleTestRead);
    bundle.extract();
    //bundle.addFile(tmpdataFile);
    //bundle.addFile(tmpformatFile);
    bundle.pack("c://testPacking.form");
/*
    BundleReader bundle(new QFile("c://testPacking.form"));
    bundle.extract();
    printf(bundle.path().toLocal8Bit());
*/

    QToolBar* mainToolBar = new QToolBar();
    mainToolBar->setMovable(true);
    mainToolBar->setFloatable(true);
    mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);


    QWidget* window = new QWidget();


    const QIcon peopleicon(":/icons/user");
    mainToolBar->addAction(peopleicon, QString("People"));

    const QIcon formsicon(":/icons/database_table");
    mainToolBar->addAction(formsicon, QString("Forms"));

    const QIcon saveicon(":/icons/database_save");
    mainToolBar->addAction(saveicon, QString("Save"));


    MainTableModel myModel(0, formatFile, dataFile);
    MainTable table(0, &myModel);



    const QIcon editicon(":/icons/application_edit");
    QAction* editaction = new QAction(editicon, QString("Edit"), window);
    mainToolBar->addAction(editaction);

    QObject::connect(editaction, SIGNAL(triggered()),
                     &table, SLOT(editSelected()));

    
    const QIcon delicon(":/icons/delete");
    QAction* deleteaction = new QAction(delicon, QString("Delete"), window);
    mainToolBar->addAction(deleteaction);

    QObject::connect(deleteaction, SIGNAL(triggered()),
                     &table, SLOT(deleteSelected()));


    const QIcon addicon(":/icons/add");
    QAction* addaction = new QAction(addicon, QString("Add"), window);
    mainToolBar->addAction(addaction);

    QObject::connect(addaction, SIGNAL(triggered()), 
                     &table, SLOT(addRow()));


    
    QMenuBar menu;

    VisibilityMenu* showhide = new VisibilityMenu(QString("Show/Hide"), formatFile, &table);

    menu.addMenu(showhide);
    mainToolBar->addWidget(&menu);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(mainToolBar);
    layout->addWidget(&table);

    window->setLayout(layout);
    window->show();

    CsvLoc dataLoc = CsvLoc(dataFile, 0, 0);
    AddDialog* dialog = new AddDialog(formatFile, &dataLoc);
    dialog->exec();
    delete dialog;
    
    return a.exec();
}
