#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>

#include"QTcpSocket"

namespace Ui {
    class clientWidget;
}

class clientWidget : public QWidget
{
    Q_OBJECT

public:
    explicit clientWidget(QWidget *parent = 0);
    ~clientWidget();

private:
    Ui::clientWidget *ui;
    QTcpSocket * cl;

public slots:
    void on_connectButton_clicked();
    void on_writeButton_clicked();
    void handleNewMsg();
    void handleConnected();
};

#endif // CLIENTWIDGET_H
