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


    formatFile->saveFile();

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


    const QIcon addicon(":/icons/add");
    QAction* addaction = new QAction(addicon, QString("Add"), window);
    mainToolBar->addAction(addaction);

    MainTableModel myModel(0, formatFile, dataFile);
    MainTable table(0, &myModel);

    QObject::connect(addaction, SIGNAL(triggered()), &table, SLOT(addRow()));


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
