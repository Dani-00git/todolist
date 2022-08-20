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
            stream << "\n";
            stream << t.getName();
            stream << "\n";
            stream << t.getDesc();
            stream << "\n";
            stream << t.getDate();
            stream << "\n";
            stream << t.getPrior();
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
            in.readLine();
            QString name = in.readLine();
            QString desc = in.readLine();
            QString date = in.readLine();
            QString prior = in.readLine();

            Task t(name,desc,date,prior);
            tasks.push_back(t);
        }
        return tasks;
    }

};
#endif // DBMS_H
