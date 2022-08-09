#ifndef TASK_H
#define TASK_H
#include "QString"


class Task
{
public:
    Task();
    Task(QString name, QString desc, QString date, QString prior){
        this->date = date;
        this->desc = desc;
        this->name = name;
        this->prior = prior;
    }
private:
    QString name;
    QString desc;
    QString date;
    QString prior;
};

#endif // TASK_H
