#ifndef TASK_H
#define TASK_H
#include "QString"


class Task
{
public:
    Task(const QString& name, const QString desc, const QString& date, const QString& prior){
        this->date = date;
        this->desc = desc;
        this->name = name;
        this->prior = prior;
        this->isDone = false;
    }
    Task(const QString& name, const QString desc, const QString& date, const QString& prior, int isDone){
        this->date = date;
        this->desc = desc;
        this->name = name;
        this->prior = prior;
        this->isDone = isDone;
    }
    const QString& getName(){
        return name;
    }
    const QString& getDesc(){
        return desc;
    }
    const QString& getDate(){
        return date;
    }
    const QString& getPrior(){
        return prior;
    }
    const bool getIsDone(){
        return isDone;
    }
    void check(){
        if(isDone == true) isDone=false;
        else    isDone=true;
    }
public:
    QString name;
    QString desc;
    QString date;
    QString prior;
    bool isDone;
};

#endif // TASK_H
