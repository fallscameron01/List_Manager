/*
  Programmer: Cameron Falls
  File: Task.cpp
  Purpose: This file contains the function implementations of the class Task which represents a task. Task is a child class of Item.
*/

#include "Task.h"

/*---------- Task Public Member Functions ----------*/

void Task::push_subtask(const Item& subtask)
{
  m_subtasks.push_back(subtask);
  return;
}

void Task::printSubtasks() const
{
  const int NUM_SUBTASKS = m_subtasks.size();

  for (int i = 0; i < NUM_SUBTASKS; i++)
  {
    cout << i << ". " << m_subtasks[i].getContent() << endl;
  }

  return;
}

/*---------- Task Friend Functions ----------*/

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