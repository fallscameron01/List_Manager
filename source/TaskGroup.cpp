#include "TaskGroup.h"

// GENERAL FILE FORMATTING
/*
  int number of tasks
  
    string content line
    short priority
    short status
  
    int number of subtasks
      string content line
      short priority
      short status
*/
istream& operator>>(istream& in, TaskGroup& group)
{
  const int LINE_LENGTH = 255;

  int num_tasks;
  int num_subtasks;
  
  string content;
  short priority;
  short temp_stat;
  Status stat;
  
  in >> num_tasks;

  for (int i = 0; i < num_tasks; i++)
  {
    Task task;

    in.ignore(LINE_LENGTH, '\n');
    getline(in, content); // content
    in >> priority;
    in >> temp_stat;
    stat = static_cast<Status>(temp_stat);
    
    task.setContent(content);
    task.setPriority(priority);
    task.setStatus(stat);

    in >> num_subtasks;
    for (int j = 0; j < num_subtasks; j++)
    {
      Item subtask;

      in.ignore(LINE_LENGTH, '\n');
      getline(in, content);
      in >> priority;
      in >> temp_stat;
      stat = static_cast<Status>(temp_stat);
      
      subtask.setContent(content);
      subtask.setPriority(priority);
      subtask.setStatus(stat);

      task.push_subtask(subtask);
    }

    group.m_tasks.push_back(task);
  }
  
  return in;
}

ostream& operator<<(ostream& out, TaskGroup& group)
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
