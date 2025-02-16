/*
  Programmer: Cameron Falls
  File: TaskGroup.h
  Purpose: This file contains the class TaskGroup, which represents a list of tasks.
*/

#ifndef TASKGROUP_H
#define TASKGROUP_H

#include <cstdio>
#include <fstream>

#include "Task.h"

using namespace std;

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
      Description: Saves the list to the file with its filename.
      Returns: none.
    */
    void saveList();

    /*
      Description: Deletes the file associated with the list.
      Returns: none.
    */
    void deleteList();

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
      Description: Pops a task from the given index in m_tasks.
      Parameters: index - the index of the task to pop.
      Returns: none.
    */
    void pop_task(const int index);

    /*
      Description: Returns the name of the list.
      Returns: string - the name of the list.
    */
    string getName() const { return m_name; }

    /*
      Description: Changes the name and filename of the list. The list is saved to the new filename.
      Parameters: name - the new name.
      Returns: none.
    */
    void setName(const string name);

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
