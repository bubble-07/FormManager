#include <QApplication>
#include <QVBoxLayout>
#include <QTableView>
#include <QToolBar>
#include <QMenu>
#include "mymodel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView tableView;
    MyModel myModel(0, new QFile("c://formatTest.csv"));
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

    QMenu selector(QString("Main"));
    selector.addAction(QString("Meh"));
    mainToolBar->addWidget(&selector);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(mainToolBar);
    layout->addWidget(&tableView);


    QWidget* window = new QWidget();
    window->setLayout(layout);
    window->show();
    
    return a.exec();
}
