#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QWidget>
#include"QDialog"
#include"itemcontainer.h"
#include"QList"
#include"flickcharm.h"

namespace Ui {
    class itemList;
}

class itemList : public QDialog
{
    Q_OBJECT

public:
    explicit itemList(QList<ItemContainer *>,QWidget *parent = 0);
    ~itemList();

    QList<ItemContainer *> m_items;

private:
    Ui::itemList *ui;

private slots:
    void on_order_clicked();
};

#endif // ITEMLIST_H
