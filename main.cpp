#include <QApplication>
#include <QAction>
#include <QVBoxLayout>
#include <QTableView>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <vector>
#include "mymodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView tableView;
    QFile* tmpformatFile = new QFile("c://formatTest.csv");
    tmpformatFile->open(QIODevice::ReadOnly);
    CsvReader* formatFile = new CsvReader(tmpformatFile);

    MyModel myModel(0, formatFile);
    tableView.setModel(&myModel);

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
    //options.push_back(selector.addAction(QString("Meh")));
    //options[0]->setCheckable(true);

    int menusize = formatFile->getNumRows();
    for (int i = 0; i < menusize; i++) {
        options.push_back(selector.addAction(formatFile->get(i, 0)));
        options[i]->setCheckable(true);
        options[i]->setChecked(true);
    }

    menu.addMenu(&selector);
    mainToolBar->addWidget(&menu);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(mainToolBar);
    layout->addWidget(&tableView);


    QWidget* window = new QWidget();
    window->setLayout(layout);
    window->show();
    
    return a.exec();
}
