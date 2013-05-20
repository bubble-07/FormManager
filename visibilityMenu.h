class VisibilityMenu : public QMenu
{
    Q_OBJECT
    public:
    VisibilityMenu(QString name, CsvReader* file, MainTable* table);

    private:
    CsvReader* formatFile;
    MainTable* table;
    std::vector<QAction*> options;
    QSignalMapper* signalMapper;
    int menusize;
};
