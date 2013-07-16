#include <QWidget>
#include <QFileDialog>
#ifndef FILESELECTOR_DEFINED
#define FILESELECTOR_DEFINED
class FileSelector : public QObject
{
    Q_OBJECT

    public:
    FileSelector(QObject* parent = 0);
    ~FileSelector();
    public slots:
    void select();
};

#endif
