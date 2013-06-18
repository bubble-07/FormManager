#include <QSpinBox>
#include <QValidator>

#ifndef BOOLFIELD_DEFINED
#define BOOLFIELD_DEFINED

class BoolField : public QSpinBox
{
    Q_OBJECT

    public:
    QString get();
    BoolField(const QString& init, QWidget * parent = 0);
    QString textFromValue(int in) const;
    int valueFromText(const QString & text) const;
    QValidator::State validate(QString & text, int & pos) const;
    
};

#endif
