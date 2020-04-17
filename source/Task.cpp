#include "Task.h"

void Task::push_subtask(const Item& subtask)
{
  m_subtasks.push_back(subtask);
  return;
}

ostream& operator<<(ostream& out, Task& task)
{
  out << "Task: " << task.m_content << endl;
  out << "\tPriority: " << task.m_priority << endl;
  out << "\tStatus: " << task.m_status << endl;
  
  if (!task.m_subtasks.empty())
  {
    out << "\tSubtasks:" << endl;
    for (Item i : task.m_subtasks)
    {
      out << i;
    }
  }
  
  return out;
}