#include <QVBoxLayout>
#include <QDialog>

#ifndef ADDDIALOG_DEFINED
#define ADDDIALOG_DEFINED
class AddDialog : public QDialog
{
    Q_OBJECT

    public:
    AddDialog();
    
    private:
    QVBoxLayout *layout;
};


#endif
