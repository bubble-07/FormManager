#include <QApplication>
#include <QSignalMapper>
#include <QAction>
#include <QVBoxLayout>
#include <QTableView>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <vector>
#include "mymodel.h"
#include "mainTable.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile* tmpformatFile = new QFile("c://formatTest.csv");
    tmpformatFile->open(QIODevice::ReadOnly);
    CsvReader* formatFile = new CsvReader(tmpformatFile);

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

    QMenuBar menu;
    QMenu selector(QString("Show/Hide"));
    std::vector<QAction*> options;

    QSignalMapper* signalMapper = new QSignalMapper(0);

    int menusize = formatFile->getNumRows();
    for (int i = 0; i < menusize; i++) {
        options.push_back(selector.addAction(formatFile->get(i, 0)));
        options[i]->setCheckable(true);
        options[i]->setChecked(true);
        signalMapper->setMapping(options[i], i);
        QObject::connect(options[i], SIGNAL(toggled(bool)), signalMapper, SLOT(map()));
    }

    menu.addMenu(&selector);
    mainToolBar->addWidget(&menu);


    MyModel myModel(0, formatFile);
    MainTable table(0, &myModel);


    QObject::connect(signalMapper, SIGNAL(mapped(int)), &table, SLOT(toggleHidden(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(mainToolBar);
    layout->addWidget(&table);


    QWidget* window = new QWidget();
    window->setLayout(layout);
    window->show();
    
    return a.exec();
}
