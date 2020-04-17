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

    string getName() const { return m_name; }

    friend ostream& operator<<(ostream& out, const TaskGroup& group);
};


#endif // !TASKGROUP_H
