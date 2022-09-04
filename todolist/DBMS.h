#ifndef DBMS_H
#define DBMS_H
#include "task.h"
#include "QFile"
#include "QTextStream"
#include "QDebug"

class DBMS
{
public:

    void deleteTasks(){
        QFile f("/Users/danielemorganti/Desktop/todolist/db.txt");
        if(f.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
        {
            f.resize(0);
            f.close();
        }
    }

    void storeTask(Task t){
        QFile file("/Users/danielemorganti/Desktop/todolist/db.txt");
        if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream stream(&file);
            stream << t.getName();
            stream << ",";
            stream << t.getDesc();
            stream << ",";
            stream << t.getDate();
            stream << ",";
            stream << t.getPrior();
            stream << ",";
            stream << t.getIsDone();
            stream << ",";
            stream << "\n";
            file.close();
        }
    }
    std::list<Task> fetchData(){

        std::list<Task> tasks;
        QFile file("/Users/danielemorganti/Desktop/todolist/db.txt");

        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return tasks;

        QTextStream in(&file);
        while(!in.atEnd()){
            QString task = in.readLine();
            QString name="";
            QString desc="";
            QString date="";
            QString prior="";
            int isDone=0;
            int i=0;
            while(task[i]!=QString(",")){
                name=name+task[i];
                i++;
            }
            i++;
            while(task[i]!=QString(",")){
                desc=desc+task[i];
                i++;
            }
            i++;
            while(task[i]!=QString(",")){
                date=date+task[i];
                i++;
            }
            i++;
            while(task[i]!=QString(",")){
                prior=prior+task[i];
                i++;
            }
            i++;
            if(task[i]==QString("1")) isDone=1;

            Task t(name,desc,date,prior,isDone);
            tasks.push_back(t);
        }
        return tasks;
    }

};
#endif // DBMS_H
