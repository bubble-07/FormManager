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
    AddDialog(CsvReader* labelFile, CsvLoc* dataLoc);
    
    private:
    QVBoxLayout *layout;
    std::vector<AbstractEntry*> entries;
};


#endif
