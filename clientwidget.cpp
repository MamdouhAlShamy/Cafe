#include "clientwidget.h"
//#include "ui_clientwidget.h"
#include"QDebug"

#include <qhostaddress.h>
clientWidget::clientWidget(QWidget *parent) :
    QWidget(parent)/*,
    ui(new Ui::clientWidget)*/
{
    //ui->setupUi(this);
    cl = new QTcpSocket();
}

clientWidget::~clientWidget()
{
//    delete ui;
}

void clientWidget::on_writeButton_clicked()
{
//    cl->write(ui->msgEdit->text().toUtf8());
//    ui->plainTextEdit->appendPlainText("Iam saying:");
//    ui->plainTextEdit->appendPlainText(ui->msgEdit->text());
//    ui->msgEdit->setText("");
}

void clientWidget::on_connectButton_clicked()
{
    cl->connectToHost(QHostAddress("127.0.0.1"),18099);
    connect(cl,SIGNAL(connected()),this,SLOT(handleConnected()));

}

void clientWidget::handleNewMsg()
{
    QString t;
    t = cl->readAll();
//    ui->plainTextEdit->appendPlainText("The King says:");
//    ui->plainTextEdit->appendPlainText(t);
}

void clientWidget::handleConnected()
{
    qDebug()<<("now connected to the KING");
    cl->write("C1_T5_IT13_Q2_EOI_IT2_Q4_EOI_EOC");
    connect(cl,SIGNAL(readyRead()),this,SLOT(handleNewMsg()));
}
