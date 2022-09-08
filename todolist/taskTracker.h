#ifndef TASKTRACKER_H
#define TASKTRACKER_H
#include <list>
using namespace std;
#include "task.h"

class TaskTracker
{
public:
    TaskTracker(){};
    void addTask(const Task& t){
        tasks.push_back(t);
    }
    void deleteTask(const QString& name){
        list<Task> newList;
        for(Task& t:tasks){
            if(t.getName() != name){
                newList.push_back(t);
            }
        }
        tasks = newList;
    }
    const list<Task>& getTasks(){
        return tasks;
    }
    void setTasks(const list<Task> tasks){
        this->tasks = tasks;
    }
    Task searchTask(const QString name){

        Task task;
        for(Task& t:tasks){
            if(t.getName()==name)   task=t;
        }
        return task;
    }

    void checkTask(const QString name){
        for(Task &t:tasks){
            if(t.getName()==name){
                t.check();
            }
        }
    }

    int completedTasks(){
        int c=0;
        for(Task t:tasks){
            if(t.getIsDone()==1)    c++;
        }
        return c;
    }
    int totalTasks(){
        int c=0;
        for(Task& t:tasks)   c++;
        return c;
    }
private:
    list<Task> tasks;
};

#endif // TASKTRACKER_H
