#include <QVBoxLayout>
#include <QDialog>
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
    AddDialog(CsvReader* labelFile);
    
    private:
    QVBoxLayout *layout;
    NumberField *test;
    BoolField *test2;
    AbstractEntry *test3;
};


#endif
