#include "StringField.h"
#include "BoolField.h"
#include "NumberField.h"
#include "../CsvLoc.h"
#include <QWidget>
#include <QtGui>
#include <QObject>
#include <QLabel>
#include <QHBoxLayout>


#ifndef ABSTRACTENTRY_DEFINED
#define ABSTRACTENTRY_DEFINED


class AbstractEntry : public QWidget
{
    Q_OBJECT

    public:
    //explicit AbstractEntry(QWidget *parent = 0);
    AbstractEntry(CsvLoc label, CsvLoc data, QWidget *parent = 0);
    //AbstractEntry(BoolField* test, QString* label, QWidget *parent = 0);
    //AbstractEntry(NumberField* test, QString* label, QWidget *parent = 0);
    ~AbstractEntry();
    void save();

    private:
    StringField* optString;
    BoolField* optBool;
    NumberField* optNumber;

    enum Type {
        STRING,
        BOOL,
        NUMBER
    };
    Type type;

    QHBoxLayout *layout;
    QString displayString;
    QLabel* label;
    CsvLoc dataLoc;

};
#endif
