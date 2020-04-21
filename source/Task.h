/*
  Programmer: Cameron Falls
  File: Task.h
  Purpose: This file contains the class Task which represents a task. Task is a child class of Item.
*/

#ifndef TASK_H
#define TASK_H

#include <vector>
using std::vector;

#include "Item.h"

class Task :
  public Item
{
  private:
    vector<Item> m_subtasks;
  public:
    void push_subtask(const Item& subtask);

    void printSubtasks() const;

    friend ostream& operator<<(ostream& out, Task& task);
};

#endif // !TASK_H
