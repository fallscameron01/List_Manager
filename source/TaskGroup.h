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
    TaskGroup(string filename, string name)
      : m_filename(filename), m_name(name)
    { }

    friend istream& operator>>(istream& in, TaskGroup group);
};


#endif // !TASKGROUP_H
