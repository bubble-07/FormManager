#include <QLineEdit>
#include <QDoubleValidator>

#ifndef STRINGFIELD_DEFINED
#define STRINGFIELD_DEFINED

class StringField : public QLineEdit
{
    Q_OBJECT

    public:
    StringField(QWidget * parent = 0);
    
    private:
    QValidator *validator;
};

#endif
