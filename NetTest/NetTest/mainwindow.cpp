#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(ui->SendButton,SIGNAL(clicked()),this,SLOT(NetButtonClick()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::NetButtonClick(){
    QHash<QString,QString> params;
    params.insert("user_ids","100500,200, 1");
    params.insert("fields","city");
    ui->ResponseLabel->setText((QString)Network::Post(params).toJson());
}
