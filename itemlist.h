/*
this class is made to display all items in a list view
*/

#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QWidget>
#include"QDialog"
#include"itemcontainer.h"
#include"QList"


namespace Ui {
    class itemList;
}

class itemList : public QDialog
{
    Q_OBJECT

public:
    explicit itemList(QList<ItemContainer *>,QWidget *parent = 0);
    ~itemList();

    //save item list internally
    QList<ItemContainer *> m_items;

private:
    Ui::itemList *ui;

private slots:
    //when usr press on order button
    void on_order_clicked();
};

#endif // ITEMLIST_H
