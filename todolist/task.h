#ifndef TASK_H
#define TASK_H
#include "QString"


class Task
{
public:
    Task(QString name, QString desc, QString date, QString prior){
        this->date = date;
        this->desc = desc;
        this->name = name;
        this->prior = prior;
    }
    QString getName(){
        return name;
    }
    QString getDesc(){
        return desc;
    }
    QString getDate(){
        return date;
    }
    QString getPrior(){
        return prior;
    }
    bool getIsDone(){
        return isDone;
    }
private:
    QString name;
    QString desc;
    QString date;
    QString prior;
    bool isDone;
};

#endif // TASK_H
