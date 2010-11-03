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

    QString Name;
    QString Info;
    QString Price;
    QString LargeImage;
    QString Nut;
    //func
    void setItemName(QString);
    void setItemInfo(QString);
    void setItemPrice(QString);
    void setItemLargeImage(QString);
    void setItemNut(QString);

private:
    Ui::DetailedItemView *ui;
};

#endif // DETAILEDITEMVIEW_H
