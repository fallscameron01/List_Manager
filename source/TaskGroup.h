/*
  Programmer: Cameron Falls
  File: TaskGroup.h
  Purpose: This file contains the class TaskGroup, which represents a list of tasks.
*/

#ifndef TASKGROUP_H
#define TASKGROUP_H

#include "Task.h"

class TaskGroup
{
  private:
    vector<Task> m_tasks;
    string m_filename;
    string m_name;
  public:
    TaskGroup(string& filename, string& name);

    TaskGroup(const TaskGroup & t);

    void loadList();
    void printTasks() const;

    void push_task(const Task& task);

    string getName() const { return m_name; }
    int getNumTasks() const { return m_tasks.size(); }
    Task& getTask(const int ind) { return m_tasks[ind]; }

    friend ostream& operator<<(ostream& out, const TaskGroup& group);
};


#endif // !TASKGROUP_H
