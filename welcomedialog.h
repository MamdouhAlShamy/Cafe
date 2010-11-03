#ifndef WELCOMEDIALOG_H
#define WELCOMEDIALOG_H

#include <QDialog>
#include"QSqlDatabase"
#include"itemcontainer.h"
#include"QList"

namespace Ui {
    class welcomeDialog;
}

class welcomeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit welcomeDialog(QWidget *parent = 0);
    ~welcomeDialog();

    QSqlDatabase *database;
    QList<ItemContainer *> items;

    //FUNCs
    bool connect2DB();
    bool fillItemsfromDB();
    void terminateTalking2DB();
    void getOSVersion();

private:
    Ui::welcomeDialog *ui;

public slots:
    void nxt();

private slots:
    void on_browse_items_button_clicked();
};

#endif // WELCOMEDIALOG_H
