#include <QLineEdit>
#include <QDoubleValidator>

#ifndef STRINGFIELD_DEFINED
#define STRINGFIELD_DEFINED


class StringField : public QLineEdit
{
    Q_OBJECT

    public:
    QString get();
    StringField(const QString& contents, QWidget * parent = 0);
    
};

#endif
