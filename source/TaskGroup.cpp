#include "TaskGroup.h"

istream& operator>>(istream& in, TaskGroup group)
{
  Task task;
  while (in >> task)
    group.m_tasks.push_back(task);
  return in;
}
