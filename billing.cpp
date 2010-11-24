#include "billing.h"
#include "ui_billing.h"

#include"QDebug"
#include"itemlist.h"

Billing::Billing(QList<ItemContainer *> items,QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Billing)
{
    ui->setupUi(this);
    clear_pressed=0;

    setSoftKeys();

    //save all items internally
    m_items=items;


    //knowing the ordered items from not ordered
    //check all items if usr wanted them
    for(int i=0;i<items.length();i++)
    {
        //check if usr wanted it and its Times not equl to 0
        if(items[i]->isWanted()&&items[i]->Times!=0)
        {
            //put ordered items in ordered_items list
            ordered_items<<items[i];
        }

    }
    //here ordered items r in ordered items List

    //layout ordered items and calc thier total cost
    displayAndCalcOrderedItems(ordered_items);

}

Billing::~Billing()
{
    delete ui;
}

//return items back to itemList
void Billing::on_back_button_clicked()
{
    //if clear is pressed
    if(clear_pressed)
    {
        for(int i=0;i<m_items.length();i++)
            m_items[i]->show();
    }

    itemList *nm=new itemList(m_items);
    nm->show();
    this->close();
}


//layout and display and calc ordered items
void Billing::displayAndCalcOrderedItems(QList<ItemContainer *> ordered_items)
{
    total_cost=0;

    //Display ordered items and calc total total_cost
    for(int i=0;i<ordered_items.length();i++)
    {
        //catch pointer to items and put them in Layout
        ui->itemsLayout->addWidget(ordered_items[i]);


        //getting price and times of order
        total_cost=total_cost
                   +
                   (ordered_items[i]->getTimes()
                    *
                    ordered_items[i]->getPrice().toFloat(0));

        qDebug()<<"[Billing]Times"<<ordered_items[i]->getTimes()<<
                "Item Price"<<ordered_items[i]->getPrice().toFloat(0)<<
                "Total"<<QString::number(total_cost);
    }

    //view Total cost
    ui->cost->setText(QString::number(total_cost));

}

void Billing::setSoftKeys()
{
    //the LEFT KEY
    //    QAction *okSoftKeyAction = new QAction(QString("Options"), this);
    //    okSoftKeyAction->setSoftKeyRole(QAction::PositiveSoftKey);
    //    connect(okSoftKeyAction, SIGNAL(triggered()), this, SLOT());
    //    addAction(okSoftKeyAction);

    //Right Button
    QAction *cancelSoftKeyAction = new QAction(QString("Back"), this);
    cancelSoftKeyAction->setSoftKeyRole(QAction::NegativeSoftKey);
    connect(cancelSoftKeyAction, SIGNAL(triggered()), this, SLOT(on_back_button_clicked()));
    addAction(cancelSoftKeyAction);

    // Create menu
    m_menu = new QMenu(this);
    m_menu->addAction("heere", this, SLOT(doIt()));

    QAction *optionsAction = new QAction("Options", this);

    // Set defined menu into Options button
    optionsAction->setMenu(m_menu);
    optionsAction->setSoftKeyRole(QAction::PositiveSoftKey);
    addAction(optionsAction);


}

void Billing::doIt()
{

}

//refresh Billing list
void Billing::mousePressEvent(QMouseEvent * event)
{
    //check ordered items
    displayAndCalcOrderedItems(ordered_items);


}

//Clearing the list
void Billing::on_clear_button_clicked()
{
    clear_pressed=1;
    //clear ordered items
    for(int i=0;i<m_items.length();i++)
    {
        m_items[i]->setTimes(0);
        m_items[i]->wanted=0;
        m_items[i]->hide();
        m_items[i]->refresh();
    }
    //clear Cost in UI
    ui->cost->setText("0");
}

