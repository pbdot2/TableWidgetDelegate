#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include "inputdelegate.h"
#include "buttondelegate.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(1);

    QStringList _header;
    _header <<"Devices"<<"Input"<<"Control"<<"Status";
    ui->tableWidget->setHorizontalHeaderLabels(_header);
    ui->tableWidget->setItemDelegateForColumn(1, new InputDelegate(this));
    ui->tableWidget->setItemDelegateForColumn(2, new ButtonDelegate(this));

    // first
    QTableWidgetItem *item0 = new QTableWidgetItem("Device 1");
    item0->setFlags(item0->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(0, 0, item0);

    // second column (dropbown)
    QTableWidgetItem *item1 = new QTableWidgetItem("DVI");
    item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(0, 1, item1);
    ui->tableWidget->openPersistentEditor((item1)); // always show dropdown

    // third colum (button)
    QTableWidgetItem *item2 = new QTableWidgetItem();
    item2->setFlags(item2->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(0, 2, item2);
    ui->tableWidget->openPersistentEditor((item2));

    // fourth column
    QTableWidgetItem *item3 = new QTableWidgetItem("On");
    item3->setFlags(item3->flags() & ~Qt::ItemIsEditable);
    ui->tableWidget->setItem(0, 3, item3);


    connect(ui->tableWidget, SIGNAL(itemChanged(QTableWidgetItem*)),
                this, SLOT(changeItem()));


}

void MainWindow::changeItem()
{
    qDebug() << "Item changed.";
}

MainWindow::~MainWindow()
{
    delete ui;
}
