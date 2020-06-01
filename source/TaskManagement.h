/*
  Programmer: Cameron Falls
  File: TaskManagement.h
  Purpose: This file contains function declarations for functions relating to tasks.
*/

#ifndef TASKMANAGEMENT_H
#define TASKMANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>

#include "TaskGroup.h"

using namespace std;

/*
  Description: Displays prompts for editing a task and its subtasks.
  Parameters: task - the selected task.
  Returns: none.
*/
void editTask(Task& task);

/*
  Description: Displays prompts for creating a new task.
  Parameters: group - the list to add the task to.
  Returns: none.
*/
void addTask(TaskGroup& group);

/*
  Description: Removes and deletes a task from a list.
  Parameters: list - the list to delete a task from.
  Returns: none.
*/
void removeTask(TaskGroup& list);

/*
  Description: Displays prompts for creating a subtask.
  Returns: Item - the subtask.
*/
Item createSubtask();

/*
  Description: Displays prompts for editing a subtask.
  Parameters: subtask - the selected subtask for editing.
  Returns: none.
*/
void editSubtask(Item& subtask);

#endif