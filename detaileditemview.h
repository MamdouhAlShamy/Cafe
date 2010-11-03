/*
 this class is QDialog made to view each item with more details like
Name
Info
large image
Price
Nutriation Table

*/

#ifndef DETAILEDITEMVIEW_H
#define DETAILEDITEMVIEW_H

#include <QDialog>



namespace Ui {
    class DetailedItemView;
}

class DetailedItemView : public QDialog
{
    Q_OBJECT

public:
    explicit DetailedItemView(QWidget *parent = 0);
    ~DetailedItemView();

    //containers to contain item data
    QString Name;
    QString Info;
    QString Price;
    QString LargeImage;
    QString Nut;

    //EOC

    //funcs to set item data
    void setItemName(QString);
    void setItemInfo(QString);
    void setItemPrice(QString);
    void setItemLargeImage(QString);
    void setItemNut(QString);

    //EOC


private:
    Ui::DetailedItemView *ui;
};

#endif // DETAILEDITEMVIEW_H
