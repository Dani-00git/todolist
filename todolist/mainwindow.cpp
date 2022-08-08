#include "mainwindow.h""
#include "./ui_mainwindow.h"
#include "QDateTime"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDateTime time = QDateTime::currentDateTime();
    setStyleSheet("background-color:white;");
    ui->label_2->setStyleSheet("font-size: 17px;");
    ui->label_3->setStyleSheet("font-size: 17px;");
    ui->label_3->setText(time.toString("dd.MM.yyyy"));
    ui->textEdit->setPlaceholderText(QString("Name"));
    ui->textEdit_2->setPlaceholderText(QString("Description"));
    ui->frame->setStyleSheet("background-color: white;"
                             "border: 1px solid gray;"
                             "border-radius:5px;");
    ui->frame_4->setStyleSheet("background-color: white;"
                               "border: 1px solid gray;"
                               "border-radius:5px;");
    ui->radioButton->setStyleSheet("border: 0px;");
    ui->radioButton_2->setStyleSheet("border: 0px;");
    ui->radioButton_3->setStyleSheet("border: 0px;");
    ui->radioButton_4->setStyleSheet("border: 0px;");
    ui->radioButton_5->setStyleSheet("border: 0px;");
    ui->radioButton_6->setStyleSheet("border: 0px;");
    ui->radioButton_7->setStyleSheet("border: 0px;");
    ui->radioButton_8->setStyleSheet("border: 0px;");
    ui->frame_5->setStyleSheet("background-color: white;"
                               "border: 1px solid gray;"
                               "border-radius:5px;");
    ui->frame_4->hide();
    ui->frame_5->hide();
    ui->pushButton->setStyleSheet("background-color: white;"
                                  "border: 1px solid gray;"
                                  "border-radius:5px;");
    ui->pushButton_5->setStyleSheet("background-color: white;"
                                  "border: 1px solid gray;"
                                  "border-radius:5px;");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->setText("");
    ui->textEdit_2->setText("");
    ui->pushButton_2->setText("Today");
    ui->pushButton_3->setText("Priority 1");
    ui->frame_4->hide();
    ui->frame_5->hide();
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->frame_4->show();
    ui->frame_5->hide();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->frame_5->show();
    ui->frame_4->hide();

}


void MainWindow::on_radioButton_clicked()
{
    ui->pushButton_2->setText("Today");
}


void MainWindow::on_radioButton_2_clicked()
{
    ui->pushButton_2->setText("Tomorrow");
}


void MainWindow::on_radioButton_3_clicked()
{
    ui->pushButton_2->setText("This Week");
}


void MainWindow::on_radioButton_4_clicked()
{
    ui->pushButton_2->setText("No Date");
}


void MainWindow::on_radioButton_5_clicked()
{
    ui->pushButton_3->setText("Priority 1");
}


void MainWindow::on_radioButton_6_clicked()
{
    ui->pushButton_3->setText("Priority 2");
}


void MainWindow::on_radioButton_7_clicked()
{
    ui->pushButton_3->setText("Priority 3");
}


void MainWindow::on_radioButton_8_clicked()
{
    ui->pushButton_3->setText("Priority 4");
}

