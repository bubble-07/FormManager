#include <QVBoxLayout>
#include <QDialog>
#include "EntryFields/NumberField.h"

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
};


#endif
