#ifndef TASKTRACKER_H
#define TASKTRACKER_H
#include <list>
using namespace std;
#include "task.h"

class TaskTracker
{
public:
    TaskTracker(){};
    void addTask(Task t){
        tasks.push_back(t);
    }
    void deleteTask(QString name){
        list<Task> newList;
        for(Task t:tasks){
            if(t.getName() != name){
                newList.push_back(t);
            }
        }
        tasks = newList;
    }
    list<Task> getTasks(){
        return tasks;
    }
    void setTasks(list<Task> tasks){
        this->tasks = tasks;
    }
    Task getTask(QString name){
        for(Task t:tasks){
            if(t.getName()==name)   return t;
        }
    }
private:
    list<Task> tasks;
};

#endif // TASKTRACKER_H
