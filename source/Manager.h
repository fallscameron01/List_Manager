/*
  Programmer: Cameron Falls
  File: Manager.h
  Purpose: This file contains function declarations for functions for use managing list from main.
*/

#ifndef MANAGER_H
#define MANAGER_H

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

// TODO: Update include for filesystem
#include <experimental/filesystem>
#include <vector>
#include <string>
#include <iostream>

#include "TaskGroup.h"

namespace fs = std::experimental::filesystem;

using namespace std;

/*---------- File Management ----------*/

/*
  Description: Loads all lists in the directory Lists/ into groups.
  Parameters: groups - holds the loaded lists
  Returns: none.
*/
void loadLists(vector<TaskGroup>& groups);

/*
  Description: Checks if a list name is valid.
  Parameters: groups - all the lists, to check if the name is already in use.
              name - the name being checked.
  Returns: bool - whether or not the name is valid.
*/
bool nameIsValid(const vector<TaskGroup>& groups, const string& name);

/*---------- Menus ----------*/

/*
  Description: Displays a menu for selecting a list.
  Parameters: groups - the lists.
  Returns: int - the index of the selected list in groups.
*/
int menuLists(const vector<TaskGroup>& groups);

/*
  Description: Displays a menu for selecting an option to perform on a selected list.
  Parameters: list - the selected list to perform an action on.
  Returns: int - the selected option.
*/
int menuTasks(const TaskGroup& list);

/*---------- List Management ----------*/

/*
  Description: Displays prompts for creating a new list.
  Parameters: gropups - the group of lists
  Returns: none.
*/
void createNewList(vector<TaskGroup>& groups);

/*---------- Task Management ----------*/

/*
  Description: Displays a menu for selecting a task from a list.
  Parameters: list - the selected list.
  Returns: int - the index of the task
*/
int menuChooseTask(const TaskGroup& list);

/*
  Description: Displays prompts for editing a task and its subtasks.
  Parameters: task - the selected task.
  Returns: none.
*/
void editTask(Task& task);

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
  Description: Displays prompts to change the name of a list.
  Parameters: groups - the vector containing all lists.
              list - the list to rename.
  Returns: none.
*/
void changeListName(const vector<TaskGroup>& groups, TaskGroup& list);

/*
  Description: Displays a confirmation prompt before the deletion of a list.
  Parameters: listName - the name of the list set to be deleted.
  Returns: bool - whether or not the deletion can proceed.
*/
bool confirmDelete(string listName);

#endif