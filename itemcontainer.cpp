#include "itemcontainer.h"
#include "ui_itemcontainer.h"
#include"QDebug"
#include"detaileditemview.h"

ItemContainer::ItemContainer(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ItemContainer)
{
    ui->setupUi(this);

    //hide remove button
    ui->remove->setVisible(0);
    ui->times->setVisible(0);

    //prepare
    no_of_same_item=1;
    wanted=0;
}

ItemContainer::~ItemContainer()
{
    delete ui;
}
///////////////////////////////////
/////////GET//////////////////////
//////////////////////////////////
QString ItemContainer::getId()
{
    return Id ;}
QString ItemContainer::getName()
{
    return Name;}
QString ItemContainer::getInfo()
{
    return Info;}
QString ItemContainer::getPrice()
{
    return Price;}
QString ItemContainer::getThumnailImage()
{
    return Thumnail_image;}
QString ItemContainer::getTimes()
{
    return Times;
}
QString ItemContainer::getLargeImage()
{
    return Large_image;
}
QString ItemContainer::getNut()
{
    return Nut;
}

///////////////////////////////////
/////////SET in Widget or internal//////////////////////
//////////////////////////////////
void ItemContainer::setId(QString id)
{
    Id=id;
}
void ItemContainer::setName(QString name)
{
    Name=name;
    ui->name->setText(name);
}
void ItemContainer::setInfo(QString info)
{
    Info=info;
}
void ItemContainer::setPrice(QString price)
{
    Price=price;
    ui->price->setText(price);
}
void ItemContainer::setThumnialImage(QString thumnail_image)
{
    Thumnail_image=thumnail_image;
    ui->thumnail_image->setPixmap(QPixmap(thumnail_image));
}
void ItemContainer::setLargeImage(QString large_image){
    Large_image=large_image;
}
void ItemContainer::setNut(QString nut)
{
    Nut=nut;
}

//WHEN usr wants the item
void ItemContainer::on_add_clicked()
{

    //to show or hide remove"-" button
    if(no_of_same_item==1) //if first time
    {
        ui->remove->setVisible(1);
        ui->times->setVisible(1);
    }

    ui->times->setText(QString::number(no_of_same_item));
    Times=ui->times->text();

    no_of_same_item++;


    wanted=1;

}


//WHEN usr dont wants the item or multi of it
void ItemContainer::on_remove_clicked()
{
    ui->times->setText(QString::number(no_of_same_item-2));
    Times=ui->times->text();
    no_of_same_item--;

    //to show or hide add"+" button
    if(no_of_same_item==1)//if usr dont need this item
    {
        ui->remove->setVisible(0);
        ui->times->setVisible(0);
    }


}


//Does usr wantes it ?
bool ItemContainer::isWanted()
{
    if(wanted==1)
        return 1;
    else
        return 0;
}

//when usr need more info on the Item
void ItemContainer::mouseDoubleClickEvent(QMouseEvent *event)
{

    DetailedItemView *nm=new DetailedItemView();
    nm->setItemName(Name);
    nm->setItemInfo(Info);
    nm->setItemPrice(Price);
    nm->setItemLargeImage(Large_image);
    nm->setItemNut(Nut);

    nm->show();


}

/*
//    writeOrder();
}

//using Flying QString Order to know Billing
//void ItemContainer::writeOrder()
//{
//    //notify that it is wanted
//    wanted=1;

//    m_order="";
//    m_order.append(Id);
//    m_order.append(",");
//    m_order.append(ui->times->text());
//    m_order.append(";");
//    qDebug()<<m_order;
//}
*/
