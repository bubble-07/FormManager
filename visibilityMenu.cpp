#include "visibilityMenu.h"

VisibilityMenu::VisibilityMenu(QString name, CsvReader* file, MainTable* table)
    :QMenu(name)
{
    this->formatFile = file;
    this->table = table;

    this->signalMapper = new QSignalMapper(0);

    this->showall = this->addAction(QString("Show All"));
    this->hideall = this->addAction(QString("Hide All"));

    QObject::connect(this->showall, SIGNAL(triggered()), this, SLOT(showAll()));
    QObject::connect(this->hideall, SIGNAL(triggered()), this, SLOT(hideAll()));

    this->menusize = this->formatFile->getNumRows();
    for (int i = 0; i < this->menusize; i++) {
        this->options.push_back(this->addAction(this->formatFile->get(i, 0)));
        this->options[i]->setCheckable(true);
        this->options[i]->setChecked(true);
        signalMapper->setMapping(this->options[i], i);
    QObject::connect(this->options[i], SIGNAL(toggled(bool)), this->signalMapper, SLOT(map()));
    }

    
QObject::connect(this->signalMapper, SIGNAL(mapped(int)), this->table, SLOT(toggleHidden(int)));
    
    return;
}

void VisibilityMenu::hideAll() {
    for (int i = 0; i < this->menusize; i++) {
        options[i]->setChecked(false);
    }
    return;
}
void VisibilityMenu::showAll() {
    for (int i = 0; i < this->menusize; i++) {
        options[i]->setChecked(true);
    }
    return;
}
