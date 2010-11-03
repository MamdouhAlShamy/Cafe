/*
this class is made to view ordered items and calc the Total price
*/

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

    //save items internally
    QList<ItemContainer *>m_items;

    //save ordered items
    QList<ItemContainer *>ordered_items;

    //>>FUNC
    //enable and use softkeys
    void setSoftKeys();

    //layout & display and calculate ordered items
    void displayAndCalcOrderedItems(QList<ItemContainer *>);

    //refresh billing Total Price
    void mousePressEvent(QMouseEvent *);

private:
    Ui::Billing *ui;

private slots:
    //go back to Item List
    void on_back_button_clicked();
    //none
    void doIt();
};

#endif // BILLING_H
