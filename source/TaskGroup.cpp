/*
  Programmer: Cameron Falls
  File: TaskGroup.cpp
  Purpose: This file contains the function implementations of the class TaskGroup, which represents a list of tasks.
*/

#include "TaskGroup.h"

/*---------- TaskGroup Public Member Functions ----------*/

TaskGroup::TaskGroup(string& filename, string& name)
  : m_filename(filename), m_name(name)
{
  loadList();
}

TaskGroup::TaskGroup(const TaskGroup& t)
  : m_filename(t.m_filename), m_name(t.m_name)
{
  loadList();
}

void TaskGroup::loadList()
{
  const int LINE_LENGTH = 255;

  int num_tasks;
  int num_subtasks;

  ifstream fin;
  fin.open(m_filename);

  string content;
  short priority;
  short temp_stat;
  Status stat;

  fin >> num_tasks;

  for (int i = 0; i < num_tasks; i++)
  {
    Task task;

    fin.ignore(LINE_LENGTH, '\n');
    getline(fin, content); // content
    fin >> priority;
    fin >> temp_stat;
    stat = static_cast<Status>(temp_stat);

    task.setContent(content);
    task.setPriority(priority);
    task.setStatus(stat);

    fin >> num_subtasks;
    for (int j = 0; j < num_subtasks; j++)
    {
      Item subtask;

      fin.ignore(LINE_LENGTH, '\n');
      getline(fin, content);
      fin >> priority;
      fin >> temp_stat;
      stat = static_cast<Status>(temp_stat);

      subtask.setContent(content);
      subtask.setPriority(priority);
      subtask.setStatus(stat);

      task.push_subtask(subtask);
    }

    m_tasks.push_back(task);
  }

  fin.close();

  return;
}

void TaskGroup::saveList()
{
  ofstream fout;
  fout.open("Lists/" + m_filename);

  fout << getNumTasks() << endl;

  for (Task & t : m_tasks)
  {
    fout << t.getContent() << endl;
    fout << t.getPriority() << endl;
    fout << t.getStatus() << endl;

    fout << t.getNumSubtasks() << endl;
    for (int i = 0; i < t.getNumSubtasks(); i++)
    {
      fout << t.getSubtask(i).getContent() << endl;
      fout << t.getSubtask(i).getPriority() << endl;
      fout << t.getSubtask(i).getStatus() << endl;
    }
  }

  fout.close();
  return;
}

void TaskGroup::printTasks() const
{
  const int NUM_TASKS = m_tasks.size();

  cout << "\t---------- Tasks ----------" << endl;

  for (int i = 0; i < NUM_TASKS; i++)
  {
    cout << (i+1) << ". " << m_tasks[i].getContent() << endl;
  }

  return;
}

void TaskGroup::push_task(const Task& task)
{
  m_tasks.push_back(task);
  return;
}

void TaskGroup::pop_task(const int index)
{
  m_tasks.erase(m_tasks.begin() + index);
  return;
}

void TaskGroup::setName(const string name)
{
  const string OLD_FILE = m_filename;

  m_filename = name + ".txt";
  m_name = name;
  saveList(); // save the list with its new filename

  remove(OLD_FILE.c_str()); // remove the old file

  return;
}

/*---------- TaskGroup Friend Functions ----------*/

ostream& operator<<(ostream& out, const TaskGroup& group)
{
  out << "Group: " << group.m_name << endl;
  out << "File: " << group.m_filename << endl;
  out << "--------------------" << endl;
  for (Task t : group.m_tasks)
  {
    out << t;
  }
  return out;
}
