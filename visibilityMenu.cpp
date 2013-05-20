#include "visibilityMenu.h"

VisibilityMenu::VisibilityMenu(QString name, CsvReader* file, MainTable* table)
    :QMenu(parent)
{
    this->formatFile = file;
    this->table = table;

    this->signalMapper = new QSignalMapper(0);

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
