#ifndef TASKTRACKER_H
#define TASKTRACKER_H
#include <list>
using namespace std;
#include "task.h"

class TaskTracker
{
public:
    TaskTracker(){

    };
    void addTask(Task t){
        tasks.push_back(t);
    }
private:
    list<Task> tasks;
};

#endif // TASKTRACKER_H
