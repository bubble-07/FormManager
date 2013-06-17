#include <QLineEdit>
#include <QDoubleValidator>
#include "AbstractField.h"

#ifndef STRINGFIELD_DEFINED
#define STRINGFIELD_DEFINED

class StringField : public QLineEdit
{
    Q_OBJECT

    public:
    StringField(const QString& contents, QWidget * parent = 0);
    
};

#endif
