#include <QLineEdit>
#include <QDoubleValidator>

#ifndef NUMBERFIELD_DEFINED
#define NUMBERFIELD_DEFINED

class NumberField : public QLineEdit
{
    Q_OBJECT

    public:
    NumberField(QWidget * parent = 0);
    
    private:
    QValidator *validator;
};

#endif