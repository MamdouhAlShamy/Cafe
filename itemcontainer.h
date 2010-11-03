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
    explicit ItemContainer(/*QString,*/QWidget *parent = 0);
    ~ItemContainer();
    int no_of_same_item;
    QString Id;
    QString Name;
    QString Info;
    QString Price;
    QString Thumnail_image;
    QString Large_image;
    QString Nut;
    QString m_order;
    QString Times;
    bool wanted;

    //FUNCTIONS
    QString getId();
    QString getName();
    QString getInfo();
    QString getPrice();
    QString getThumnailImage();
    QString getLargeImage();
    QString getNut();
    QString getTimes();
    void mouseDoubleClickEvent(QMouseEvent *);

    void setId(QString);
    void setName(QString);
    void setInfo(QString);
    void setPrice(QString);
    void setThumnialImage(QString);
    void setLargeImage(QString);
    void setNut(QString);
    bool isWanted();

    void writeOrder();

private:
    Ui::ItemContainer *ui;

private slots:
    void on_remove_clicked();
    void on_add_clicked();
};

#endif // ITEMCONTAINER_H
