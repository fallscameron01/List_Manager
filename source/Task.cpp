#include "Task.h"

// GENERAL STORAGE FORMATTING
/*
  string content line
  short priority
  short status
  int number of subtasks
  subtasks
*/
istream& operator>>(istream& in, Task task)
{
  short temp;
  int num_subtasks;

  getline(in, task.m_content);
  in >> task.m_priority;
  in >> temp;
  task.m_status = static_cast<Status>(temp);
  
  in >> num_subtasks;
  
  for (int i = 0; i < num_subtasks; i++)
  {
    Task sub;
    in >> sub;

    task.m_subtasks.push_back(sub);
  }

  return in;
}
