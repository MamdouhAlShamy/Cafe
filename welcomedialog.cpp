#include "welcomedialog.h"
#include "ui_welcomedialog.h"
#include"QDebug"
#include"QSqlQuery"
#include"itemlist.h"
#include"QSysInfo"
#include"clientwidget.h"

welcomeDialog::welcomeDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::welcomeDialog)
{
    ui->setupUi(this);

    //knowing version of OS
    //    getOSVersion();

    //    //connect to Server
    clientWidget *nj=new clientWidget;
    nj->on_connectButton_clicked();

    qDebug()<<"connecting..";

    //connect to DB and reterive all data
    bool DB= connect2DB();

    if(DB)
        qDebug()<<"[welcomeDialogdialog]Connected to DB :SUCCEDED";
    else
        qDebug()<<"[welcomeDialogdialog]Connected to DB :FAILED";


    //fill items list
    bool FILL=fillItemsfromDB();

    if(FILL)
        qDebug()<<"[welcomeDialogdialog]Filling items from DB :SUCCEDED";
    else
        qDebug()<<"[welcomeDialogdialog]Filling items from DB :FAILED";

    //close DB and remove connection
    terminateTalking2DB();



}

welcomeDialog::~welcomeDialog()
{
    delete ui;
}

bool welcomeDialog::connect2DB()
{
    database = new QSqlDatabase();

    //set database driver to QSQLITE
    *database = QSqlDatabase::addDatabase("QSQLITE");


        database->setDatabaseName("./DB.db"); //windows version

//        database->setDatabaseName("C:\DB.db"); //Symbian


    //can be removed
    database->setHostName("localhost");
    database->setUserName("");
    database->setPassword("");

    if(!database->open())
        return 0;
    else
        return 1;

}

bool welcomeDialog::fillItemsfromDB()
{
    //QUERYing DB "database"
    QSqlQuery query("SELECT * FROM Food",*database);

    while(query.next())
    {
        QString Foodid=query.value(0).toString();
        QString Name=query.value(1).toString();
        QString Info=query.value(2).toString();
        QString Price=query.value(3).toString();
        QString Thumnail_image=query.value(4).toString();
        QString Large_image=query.value(5).toString();
        QString Nut=query.value(6).toString();


        //each item will write the order in it
        //////////////////////////////////////////////////////////////////////////////////////////////
        //fill Item WINDOW
        /////////////////////////////////////////////////////////////////////////////////////        //

        //making instance of ItemContainer
        ItemContainer *no1=new ItemContainer(/*order*/);

        //put instance in list
        items<<no1;

        //fit ItemContainer in layout
        //        ui->itemsLayout->addWidget(no1);   will fill the layout in next widget isA

        //fill ItemContainer from DB
        no1->setId(Foodid);
        no1->setName(Name);
        no1->setInfo(Info);
        no1->setPrice(Price);
        no1->setThumnialImage(Thumnail_image);
        no1->setLargeImage(Large_image);
        no1->setNut(Nut);

    }
    return 1;
}

//close DB and remove connection
void welcomeDialog::terminateTalking2DB()
{
    //close connection to DB
    database->close();

    //remove DB connection
    QSqlDatabase::removeDatabase("database");
}



void welcomeDialog::getOSVersion()
{

    //    //get OS version
    //    switch(QSysInfo::)
    //    {
    //    case QSysInfo::WV_WINDOWS7:
    //        qDebug()<<"The program is working on Windows 7";
    //        break;

    //    case QSysInfo::WV_XP:
    //        qDebug()<<"The program is working on Windows XP";
    //        break;

    //    default:
    //        qDebug()<<"The program is working on MAY be LINUX";
    //        break;

    //    }

}

void welcomeDialog::nxt()
{
    itemList *itemLists=new itemList(items);

    itemLists->show();
    this->close();
}

void welcomeDialog::on_browse_items_button_clicked()
{
    nxt();
}
