#include <QtTest>
#include "../todolist/taskTracker.h"
#include "../todolist/DBMS.h"
#include "../todolist/task.h"

class todolistTesting : public QObject
{
    Q_OBJECT

private slots:
    void taskTrackerTester();
    void taskTester();
    void DBMStester();
    void countTester();

private:
    TaskTracker tt;
};

void todolistTesting::taskTrackerTester()
{
    Task t1("task1","","","");
    Task t2("task2","","","");
    tt.addTask(t1);
    tt.addTask(t2);
    QCOMPARE(tt.searchTask("task1").getName(),t1.getName());
    QCOMPARE(tt.searchTask("task2").getName(),t2.getName());
    tt.deleteTask(t1.getName());
    QString name = tt.getTasks().begin()->getName();
    QCOMPARE(name, t2.getName());
    tt.deleteTask(t2.getName());
}
void todolistTesting::taskTester(){
    Task t("task","a description","today","priority 1");
    QCOMPARE(t.getName(),"task");
    QCOMPARE(t.getDesc(),"a description");
    QCOMPARE(t.getDate(),"today");
    QCOMPARE(t.getPrior(),"priority 1");
}
void todolistTesting::countTester(){
    Task t1("task1","","","",0);
    Task t2("task2","","","",0);
    Task t3("task3","","","",0);
    Task t4("task4","","","",0);
    tt.addTask(t1);
    tt.addTask(t2);
    tt.addTask(t3);
    tt.addTask(t4);
    tt.checkTask("task1");
    tt.checkTask("task2");
    QCOMPARE(tt.completedTasks(), 2);
    QCOMPARE(tt.totalTasks(), 4);
}
void todolistTesting::DBMStester(){
    DBMS dbms;
    Task t("task","a description","today","priority 1");
    dbms.storeTask(t);
    QCOMPARE(dbms.fetchData().begin()->getName(),"task");
    dbms.deleteTasks();
}

QTEST_APPLESS_MAIN(todolistTesting)

#include "tst_todolisttesting.moc"
