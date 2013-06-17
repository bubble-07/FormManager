#include <QVBoxLayout>
#include <QDialog>
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
    AddDialog();
    
    private:
    QVBoxLayout *layout;
    NumberField *test;
    BoolField *test2;
    AbstractEntry *test3;
};


#endif
