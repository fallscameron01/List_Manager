/*
  Programmer: Cameron Falls
  File: TaskGroup.h
  Purpose: This file contains the class TaskGroup, which represents a list of tasks.
*/

#ifndef TASKGROUP_H
#define TASKGROUP_H

#include "Task.h"

// The TaskGroup class represents a list of tasks.
class TaskGroup
{
  private:
    vector<Task> m_tasks; // the tasks belonging to the group
    string m_filename; // the name of the file in which the list is stored
    string m_name; // the name of the list

  public:

    /*
      Description: Constructs a TaskGroup using the given filename and list name.
      Parameters: filename - name of file to construct list from.
                  name - name of the list.
    */
    TaskGroup(string& filename, string& name);

    /*
      Description: Constructs a TaskGroup by copying the given TaskGroup.
      Parameters: t - TaskGroup to copy.
    */
    TaskGroup(const TaskGroup & t);

    /*
      Description: Loads a list from the file with the name m_filename.
      Returns: none.
    */
    void loadList();

    /*
      Description: Prints the tasks' content to the console with an associated number.
      Returns: none.
    */
    void printTasks() const;

    /*
      Description: Pushes a task to the back of m_tasks.
      Parameters: task - the task to push.
      Returns: none.
    */
    void push_task(const Task& task);

    /*
      Description: Returns the name of the list.
      Returns: string - the name of the list.
    */
    string getName() const { return m_name; }

    /*
      Description: Returns the number of tasks in the list.
      Returns: int - the number of tasks.
    */
    int getNumTasks() const { return m_tasks.size(); }

    /*
      Description: Returns the task stored at the given index in m_tasks.
      Parameters: ind - the index of the task.
      Returns: Task - the task at the given index.
    */
    Task& getTask(const int ind) { return m_tasks[ind]; }

    /*
      Description: Outputs the given TaskGroup to the ostream.
      Parameters: out - the ostream to output to.
                  group - the group to output.
      Returns: ostream - the given ostream.
    */
    friend ostream& operator<<(ostream& out, const TaskGroup& group);
};


#endif // !TASKGROUP_H
