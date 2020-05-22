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
      Description: Pops a subtask at the given index in m_subtasks.
      Parameters: index - the index of the subtask to pop.
      Returns: none.
    */
    void pop_subtask(const int index);

    /*
      Description: Prints the subtasks of the task to the console.
      Returns: none.
    */
    void printSubtasks() const;

    /*
      Description: Returns the number of subtasks.
      Returns: int - number of subtasks in m_subtasks.
    */
    int getNumSubtasks() const { return m_subtasks.size(); }

    /*
      Description: Returns the subtask stored at the given index in m_subtasks.
      Parameters: index - the index of the subtask.
      Returns: Item - the subtask at the given index.
    */
    Item& getSubtask(const int index) { return m_subtasks[index]; }

    /*
      Description: Outputs the given Task to the ostream.
      Parameters: out - the ostream to output to.
                  task - the Task to output.
      Returns: ostream - the given ostream.
    */
    friend ostream& operator<<(ostream& out, Task& task);
};

#endif // !TASK_H
