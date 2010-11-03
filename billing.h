#ifndef BILLING_H
#define BILLING_H

#include <QDialog>
#include"QtSql/QSqlDatabase"
#include"itemcontainer.h"
#include"itemcontainer.h"
#include"QMenu"

namespace Ui {
    class Billing;
}

class Billing : public QDialog
{
    Q_OBJECT

public:
    explicit Billing(QList<ItemContainer *>,QWidget *parent = 0);
    ~Billing();

    // Instance variable for header
    QMenu* m_menu;
    float total_cost;

    QList<ItemContainer *>m_items;
    QList<ItemContainer *>ordered_items;

    void setSoftKeys();
    void displayAndCalcOrderedItems(QList<ItemContainer *>);
    void mousePressEvent(QMouseEvent *);

private:
    Ui::Billing *ui;

private slots:
    void on_back_button_clicked();
    void doIt();
};

#endif // BILLING_H
