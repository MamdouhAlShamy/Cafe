#include "itemlist.h"
#include "ui_itemlist.h"
#include "billing.h"
//#include"QPropertyAnimation"

itemList::itemList(QList<ItemContainer *> items,QWidget *parent) :
        QDialog(parent),
        ui(new Ui::itemList)
{
    ui->setupUi(this);
    //billing ICON
    ui->order->setIcon(QIcon("./images/File_64.png"));


    //take item list and put it in itemsLayout
    for(int i=0;i<items.length();i++)
    {
        ui->itemsLayout->addWidget(items[i]);
    }

    //passing items to order button
    m_items=items;


    //    //ANIMATION
    //    QPropertyAnimation *animation = new QPropertyAnimation(ui->scrollAreaWidgetContents, "geometry");
    //    animation->setDuration(10000);
    //    animation->setStartValue(QRect(0, 0, 100, 30));
    //    animation->setEndValue(QRect(250, 250, 100, 30));
    //    animation->setEasingCurve(QEasingCurve::InOutQuad);

    //    animation->start();

    //kinetice Scrolling
//    FlickCharm FlickCharm;
//    FlickCharm.activateOn(ui->scrollArea);
}

itemList::~itemList()
{
    delete ui;
}

//when usr press on order button
void itemList::on_order_clicked()
{
    Billing *bill=new Billing(m_items);
    bill->show();
    this->close();
}

