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
#include "mymodel.h"
#include "mainTable.h"
#include "visibilityMenu.h"
#include "addDialog.h"
#include "EntryFields/NumberField.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile* tmpformatFile = new QFile("c://formatTest.csv");
    tmpformatFile->open(QIODevice::ReadOnly);
    CsvReader* formatFile = new CsvReader(tmpformatFile);

    formatFile->saveFile();

    QToolBar* mainToolBar = new QToolBar();
    mainToolBar->setMovable(true);
    mainToolBar->setFloatable(true);
    mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);


    const QIcon peopleicon(":/icons/user");
    mainToolBar->addAction(peopleicon, QString("People"));

    const QIcon formsicon(":/icons/database_table");
    mainToolBar->addAction(formsicon, QString("Forms"));

    const QIcon saveicon(":/icons/database_save");
    mainToolBar->addAction(saveicon, QString("Save"));

    const QIcon addicon(":/icons/add");
    mainToolBar->addAction(addicon, QString("Add"));

    MyModel myModel(0, formatFile);
    MainTable table(0, &myModel);


    QMenuBar menu;

    VisibilityMenu* showhide = new VisibilityMenu(QString("Show/Hide"), formatFile, &table);

    menu.addMenu(showhide);
    mainToolBar->addWidget(&menu);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(mainToolBar);
    layout->addWidget(&table);

    QWidget* window = new QWidget();
    window->setLayout(layout);
    window->show();

    AddDialog* dialog = new AddDialog();
    dialog->show();
    
    return a.exec();
}
