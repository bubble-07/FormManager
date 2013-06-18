#include <QLineEdit>
#include <QDoubleValidator>

#ifndef NUMBERFIELD_DEFINED
#define NUMBERFIELD_DEFINED

class NumberField : public QLineEdit
{
    Q_OBJECT

    public:
    QString get();
    NumberField(const QString& init, QWidget * parent = 0);
    
    private:
    QValidator *validator;
};

#endif
