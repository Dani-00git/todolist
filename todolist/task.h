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
        this->isDone = 0;
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
    void check(){
        if(isDone == 0) isDone=1;
        else    isDone=0;
    }
private:
    QString name;
    QString desc;
    QString date;
    QString prior;
    bool isDone;
};

#endif // TASK_H
