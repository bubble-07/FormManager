#include <QVBoxLayout>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDialog>
#include <QPushButton>
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
    AddDialog(CsvReader* labelFile, CsvLoc* dataLoc, int entryFocus = -1);
    void closeEvent(QCloseEvent *event);
    ~AddDialog();
    
    private:
    QVBoxLayout *viewLayout;
    std::vector<AbstractEntry*> entries;
    QWidget* displayArea;
    QScrollArea* scrollArea;
    QVBoxLayout *windowLayout;
    QPushButton *doneButton;

    void setFieldFocus(int pos);

    void close(bool warn);

    public slots:
    void saveAllAndExit();
    void reject();
};


#endif
