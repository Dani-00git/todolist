#include <QtTest>
#include "/Users/danielemorganti/Desktop/todolist/taskTracker.h"
#include "/Users/danielemorganti/Desktop/todolist/DBMS.h"
#include "/Users/danielemorganti/Desktop/todolist/task.h"
// add necessary includes here

class todolistTesting : public QObject
{
    Q_OBJECT

private slots:
    void taskTrackerTester();
    void taskTester();
    void DBMStester();

private:
    TaskTracker tt;
};

void todolistTesting::taskTrackerTester()
{
    Task t1("task1","","","");
    Task t2("task2","","","");
    tt.addTask(t1);
    tt.addTask(t2);
    QCOMPARE(tt.getTask("task1").getName(),t1.getName());
    QCOMPARE(tt.getTask("task2").getName(),t2.getName());
    tt.deleteTask(t1.getName());
    QCOMPARE(tt.getTasks().begin()->getName(),t2.getName());
}
void todolistTesting::taskTester(){
    Task t("task","a description","today","priority 1");
    QCOMPARE(t.getName(),"task");
    QCOMPARE(t.getDesc(),"a description");
    QCOMPARE(t.getDate(),"today");
    QCOMPARE(t.getPrior(),"priority 1");
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
