#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    this->init();
    return;
}

void MainWindow::init() {
    QFile* tmpformatFile = new QFile("c://formatTest.csv");
    tmpformatFile->open(QIODevice::ReadOnly);
    this->formatFile = new CsvReader(tmpformatFile);

    QFile* tmpdataFile = new QFile("c://dataTest.csv");
    tmpdataFile->open(QIODevice::ReadOnly);
    this->dataFile = new CsvReader(tmpdataFile);

    QFile* bundleTest = new QFile("c://siwwy.csv");
    bundleTest->open(QFile::Text | QFile::ReadWrite);
    CsvReader* bundleTestRead = new CsvReader(bundleTest);

    BundleReader bundle(bundleTestRead);
    bundle.extract();
    //bundle.addFile(tmpdataFile);
    //bundle.addFile(tmpformatFile);
    //bundle.pack();
/*
    BundleReader bundle(new QFile("c://testPacking.form"));
    bundle.extract();
    printf(bundle.path().toLocal8Bit());
*/

    this->mainToolBar = new QToolBar();
    mainToolBar->setMovable(true);
    mainToolBar->setFloatable(true);
    mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    this->mainSelector = new FileSelector();

    const QIcon openicon(":/icons/folder.png");
    this->openaction = new QAction(openicon, QString("Open"), this);
    mainToolBar->addAction(openaction);

    QObject::connect(openaction, SIGNAL(triggered()),
                     mainSelector, SLOT(select()));



    const QIcon peopleicon(":/icons/user");
    mainToolBar->addAction(peopleicon, QString("People"));

    const QIcon formsicon(":/icons/database_table");
    mainToolBar->addAction(formsicon, QString("Forms"));

    const QIcon saveicon(":/icons/database_save");
    mainToolBar->addAction(saveicon, QString("Save"));


    this->myModel = new MainTableModel(0, formatFile, dataFile);
    this->table = new MainTable(0, myModel);



    const QIcon editicon(":/icons/application_edit");
    this->editaction = new QAction(editicon, QString("Edit"), this);
    mainToolBar->addAction(editaction);

    QObject::connect(editaction, SIGNAL(triggered()),
                     table, SLOT(editSelected()));

    
    const QIcon delicon(":/icons/delete");
    this->deleteaction = new QAction(delicon, QString("Delete"), this);
    mainToolBar->addAction(deleteaction);

    QObject::connect(deleteaction, SIGNAL(triggered()),
                     table, SLOT(deleteSelected()));


    const QIcon addicon(":/icons/add");
    this->addaction = new QAction(addicon, QString("Add"), this);
    mainToolBar->addAction(addaction);

    QObject::connect(addaction, SIGNAL(triggered()), 
                     table, SLOT(addRow()));


    
    QMenuBar menu;

    this->showhide = new VisibilityMenu(QString("Show/Hide"), formatFile, table);

    menu.addMenu(showhide);
    mainToolBar->addWidget(&menu);


    this->layout = new QVBoxLayout;
    layout->addWidget(mainToolBar);
    layout->addWidget(table);


    this->setLayout(layout);


    //CsvLoc dataLoc = CsvLoc(dataFile, 0, 0);
    //AddDialog* dialog = new AddDialog(formatFile, &dataLoc);
    //dialog->exec();
    //delete dialog;
} 
