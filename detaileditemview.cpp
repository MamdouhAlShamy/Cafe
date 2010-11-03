#include "detaileditemview.h"
#include "ui_detaileditemview.h"

DetailedItemView::DetailedItemView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailedItemView)
{
    ui->setupUi(this);
}

DetailedItemView::~DetailedItemView()
{
    delete ui;
}

void DetailedItemView::setItemName(QString name)
{
    Name=name;
    ui->item_name->setText(name);

}

void DetailedItemView::setItemInfo(QString info)
{
    Info=info;
    ui->item_info->setText(info);
}

void DetailedItemView::setItemLargeImage(QString large_image)
{
    LargeImage=large_image;
    ui->item_large_image->setPixmap(QPixmap(large_image));
}

void DetailedItemView::setItemPrice(QString price)
{
    Price=price;
    ui->item_price->setText(price);
}

void DetailedItemView::setItemNut(QString nut)
{
    Nut=nut;
    ui->item_nut->setText(Nut);
}
