#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDateTime"
#include <iostream>
#include "task.h"
//#include "taskTracker.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDateTime time = QDateTime::currentDateTime();
    setStyleSheet("background-color:#E0E0E0;");
    ui->label_2->setStyleSheet("font-size: 17px;");
    ui->label_4->setStyleSheet("border: 0px solid gray;"
                               "font-size: 17px;");
    ui->label_3->setStyleSheet("font-size: 17px;");
    ui->label_3->setText(time.toString("dd.MM.yyyy"));
    ui->textEdit->setPlaceholderText(QString("Name"));
    ui->textEdit_2->setPlaceholderText(QString("Description"));
    ui->frame->setStyleSheet("background-color: whitesmoke;"
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
    this->frame4ON = 0;
    this->frame5ON = 0;
    ui->pushButton->setStyleSheet("background-color: white;"
                                  "border: 1px solid gray;"
                                  "border-radius:5px;");
    ui->pushButton_5->setStyleSheet("background-color: white;"
                                  "border: 1px solid gray;"
                                  "border-radius:5px;");
    ui->frame_2->setStyleSheet("background-color: white;"
                               "border: 1px solid gray;"
                               "border-botton: 1px solid gray;"
                               "border-radius:5px;");
    ui->checkBox->setStyleSheet("background-color: white;"
                                "border: 0px solid gray;"
                                "border-botton: 0px solid gray;");
    ui->label->setStyleSheet("background-color: white;"
                             "border: 0px solid gray;"
                             "border-botton: 0px solid gray;");
    ui->textBrowser->setStyleSheet("background-color: white;"
                              "border: 0px solid gray;");
    ui->label_6->setStyleSheet("background-color: white;"
                                "border: 0px solid gray;");
    ui->label_7->setStyleSheet("background-color: white;"
                                "border: 0px solid gray;");
    ui->frame_2->hide();
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
    if(frame4ON == 1) {
        ui->frame_4->hide();
        frame4ON = 0;
    }
    if(frame4ON == 0) {
        ui->frame_4->show();
        frame4ON = 1;
    }
    ui->frame_5->hide();
    frame5ON = 0;
}


void MainWindow::on_pushButton_3_clicked()
{
    if(frame5ON == 1) {
        ui->frame_5->hide();
        frame5ON = 0;
    }
    if(frame5ON == 0) {
        ui->frame_5->show();
        frame5ON = 1;
    }
    ui->frame_4->hide();
    frame4ON = 0;
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
void MainWindow::on_pushButton_5_clicked()
{
    ui->frame_4->hide();
    ui->frame_5->hide();
    QString name = ui->textEdit->toPlainText();
    QString desc = ui->textEdit_2->toPlainText();
    QString date = ui->pushButton_2->text();
    QString prior = ui->pushButton_3->text();
    Task t(name, desc, date, prior);
    tt.addTask(t);
    ui->frame_2->show();
    ui->label->setText(name);
    ui->textBrowser->setText(desc);
    ui->label_6->setText(date);
    ui->label_7->setText(prior);

}
