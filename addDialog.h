#include <QVBoxLayout>
#include <QDialog>
#include <QScrollArea>
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
    AddDialog(CsvReader* labelFile, CsvLoc* dataLoc);
    
    private:
    QVBoxLayout *viewLayout;
    std::vector<AbstractEntry*> entries;
    QWidget* displayArea;
    QScrollArea* scrollArea;
    QVBoxLayout *windowLayout;
};


#endif
