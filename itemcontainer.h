/*
 this class is made to represent each item with
 id
 Name
 Info
 Price
 Thumnail image
 large image
 Nutrition table
 number of times order

*/

#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H

#include <QWidget>

namespace Ui {
    class ItemContainer;
}

class ItemContainer : public QWidget
{
    Q_OBJECT

public:
    explicit ItemContainer(QWidget *parent = 0);
    ~ItemContainer();
    int no_of_same_item;

    //container for data of item
    QString Id;
    QString Name;
    QString Info;
    QString Price;
    QString Thumnail_image;
    QString Large_image;
    QString Nut;
    QString Times;
    bool wanted;

    //FUNCTIONS
    //get
    QString getId();
    QString getName();
    QString getInfo();
    QString getPrice();
    QString getThumnailImage();
    QString getLargeImage();
    QString getNut();
    QString getTimes();

    //set
    void setId(QString);
    void setName(QString);
    void setInfo(QString);
    void setPrice(QString);
    void setThumnialImage(QString);
    void setLargeImage(QString);
    void setNut(QString);
    bool isWanted();

    //what happen when usr Double Click on item
    void mouseDoubleClickEvent(QMouseEvent *);


private:
    Ui::ItemContainer *ui;

private slots:
    void on_remove_clicked();
    void on_add_clicked();
};

#endif // ITEMCONTAINER_H
