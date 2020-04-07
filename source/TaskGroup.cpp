#include "TaskGroup.h"

istream& operator>>(istream& in, TaskGroup group)
{
  Task task;
  while (in >> task)
    group.m_tasks.push_back(task);
  return in;
}

ostream& operator<<(ostream& out, TaskGroup group)
{
  out << "Group: " << group.m_name << endl;
  out << "File: " << group.m_filename << endl;
  out << "--------------------" << endl;
  for (Task t : group.m_tasks)
  {
    out << t << endl;
  }
  return out;
}
