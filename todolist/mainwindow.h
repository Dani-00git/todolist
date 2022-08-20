#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtWidgets/qframe.h"
#include "taskTracker.h"
#include "task.h"
#include "list"
#include "DBMS.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void build();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

    void on_pushButton_5_clicked();

    void delTask(int i);

    QFrame* getFrame(int i);
    void check(int i);

private:
    Ui::MainWindow *ui;
    bool frame4ON;
    bool frame5ON;
    TaskTracker tt;
    int taskPosition;
    list<QFrame*> taskFrames;
    DBMS dbms;
};
#endif // MAINWINDOW_H
