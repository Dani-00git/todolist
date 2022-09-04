#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDateTime"
#include "QScrollArea"
#include "QTextBrowser"
#include "QCheckBox"
#include <iostream>
#include "QtCore/qobjectdefs.h"
#include "task.h"
#include "taskTracker.h"
#include <fstream>
#include "QFile"
#include "QTextStream"
#include "DBMS.h"
#include "QSignalMapper"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->taskPosition=0;
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
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->scrollArea->setWidgetResizable(true);

    tt.setTasks(dbms.fetchData());
    build();
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
QFrame* MainWindow::getFrame(int i)
{
    int j=0;
    for(QFrame* f:this->taskFrames){
        if(j==i)    return f;
        j++;
    }
}
void MainWindow::delTask(int i)
{
    QFrame* frame = this->getFrame(i);
    QString name = frame->findChild<QLabel*>("label")->text();
    this->tt.deleteTask(name);
    dbms.deleteTasks();
    for(Task t:tt.getTasks())
        dbms.storeTask(t);
    build();
}
void MainWindow::check(int i){
    QFrame* frame = this->getFrame(i);
    QString name = frame->findChild<QLabel*>("label")->text();
    tt.checkTask(name);
    dbms.deleteTasks();
    for(Task t:tt.getTasks())
        dbms.storeTask(t);
    build();
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
    build();
    dbms.storeTask(t);
    ui->scrollAreaWidgetContents->setGeometry(0,0,819,1000+tt.getTasks().size());
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->pushButton_2->setText("Today");
    ui->pushButton_3->setText("Priority 1");
}
void MainWindow::build(){

    for(QFrame* f:taskFrames) f->close();
    taskFrames.clear();
    taskPosition=0;
    QSignalMapper* deleteMapper = new QSignalMapper (this);
    QSignalMapper* checkboxMapper = new QSignalMapper (this);
    int i=0;

    if(tt.totalTasks()>0){
        QLabel* header = new QLabel(ui->scrollAreaWidgetContents);
        header->setObjectName("header");
        header->setGeometry(125, 340, 521, 16);
        header->setText("task completati: "+ QString::number(tt.completedTasks())+" su un totale di: "+QString::number(tt.totalTasks()));
        header->show();
    }

    for(Task t:tt.getTasks()){
        QFrame* newFrame = new QFrame(ui->scrollAreaWidgetContents);
        this->taskFrames.push_back(newFrame);
        newFrame->lower();
        QPoint pos = ui->scrollAreaWidgetContents->mapToGlobal(ui->scrollAreaWidgetContents->rect().topLeft());
        ui->scrollAreaWidgetContents->setGeometry(0, 0, 500, 1000+taskPosition);
        newFrame->setGeometry(120, 365+taskPosition, 581, 111);
        taskPosition += 131;
        newFrame->setStyleSheet("background-color: white;"
                                "border: 1px solid gray;"
                                "border-radius:5px;");
        newFrame->show();

        QCheckBox* cb = new QCheckBox(newFrame);
        cb->setObjectName("cb");
        cb->setGeometry(10, 10, 25, 25);
        cb->setStyleSheet("background-color: white;"
                          "border: 0px solid gray;");
        cb->setChecked(t.getIsDone());
        cb->show();
        QObject::connect(cb, SIGNAL(clicked()), checkboxMapper, SLOT(map()));
        checkboxMapper->setMapping(cb, i);

        QLabel* label = new QLabel(newFrame);
        label->setObjectName("label");
        label->setGeometry(40, 10, 521, 16);
        label->setStyleSheet("background-color: white;"
                          "border: 0px solid gray;");
        label->setText(t.getName());
        label->show();

        QTextBrowser* tb = new QTextBrowser(newFrame);
        tb->setGeometry(40, 30, 521, 41);
        tb->setStyleSheet("background-color: white;"
                          "border: 0px solid gray;");
        tb->setText(t.getDesc());
        tb->show();

        QLabel* dateLabel = new QLabel(newFrame);
        dateLabel->setGeometry(40, 80, 121, 16);
        dateLabel->setStyleSheet("background-color: white;"
                                "border: 0px solid gray;");
        dateLabel->setText(t.getDate());
        dateLabel->show();

        QLabel* priorLabel = new QLabel(newFrame);
        priorLabel->setGeometry(180, 80, 111, 16);
        priorLabel->setStyleSheet("background-color: white;"
                                "border: 0px solid gray;");
        priorLabel->setText(t.getPrior());
        priorLabel->show();

        QPushButton* del = new QPushButton(newFrame);
        del->setGeometry(550, 10, 20, 20);
        del->setStyleSheet("background-color: white;"
                          "border: 1px solid gray;");
        del->setText("X");
        del->show();

        QObject::connect(del, SIGNAL(clicked()), deleteMapper, SLOT(map()));
        deleteMapper->setMapping(del, i);
        i++;
    }
    connect(deleteMapper, SIGNAL(mappedInt(int)), this, SLOT(delTask(int)));
    connect(checkboxMapper, SIGNAL(mappedInt(int)), this, SLOT(check(int)));
}

