#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDateTime"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDateTime time = QDateTime::currentDateTime();
    ui->label_3->setText(time.toString("dd.MM.yyyy"));
    ui->frame->setStyleSheet("QLabel{border-radius: 25px;}");
    ui->textEdit->setPlaceholderText(QString("Name"));
    ui->textEdit_2->setPlaceholderText(QString("Description"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

