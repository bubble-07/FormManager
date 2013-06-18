#include <QVBoxLayout>
#include <QDialog>
#include <vector>
#include "CsvLoc.h"
#include "EntryFields/NumberField.h"
#include "EntryFields/BoolField.h"
#include "EntryFields/StringField.h"
#include "EntryFields/AbstractEntry.h"

#ifndef ADDDIALOG_DEFINED
#define ADDDIALOG_DEFINED
class AddDialog : public QDialog
{
    Q_OBJECT

    public:
    AddDialog(CsvReader* labelFile, CsvReader* dataFile);
    
    private:
    QVBoxLayout *layout;
    //NumberField *test;
    //BoolField *test2;
    //AbstractEntry *test3;
    std::vector<AbstractEntry*> entries;
};


#endif
