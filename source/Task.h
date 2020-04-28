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

// The Task class represents a task. Task is a public child of Item.
class Task :
  public Item
{
  private:
    vector<Item> m_subtasks; // subtasks of the task

  public:

    /*
      Description: Pushes a subtask to the back of m_subtasks.
      Parameters: subtask - the subtask to push.
      Returns: none.
    */
    void push_subtask(const Item& subtask);

    /*
      Description: Prints the subtasks of the task to the console.
      Returns: none.
    */
    void printSubtasks() const;

    /*
      Description: Outputs the given Task to the ostream.
      Parameters: out - the ostream to output to.
                  task - the Task to output.
      Returns: ostream - the given ostream.
    */
    friend ostream& operator<<(ostream& out, Task& task);
};

#endif // !TASK_H
