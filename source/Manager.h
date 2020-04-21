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

// loads all the lists in the directory
void loadLists(vector<TaskGroup>& groups);

bool nameIsValid(const vector<TaskGroup>& groups, const string& name);

/*---------- Menus ----------*/

// Menu for selecting a list
int menuLists(const vector<TaskGroup>& groups);

// Menu for options on a list
int menuTasks(const TaskGroup& list);

/*---------- List Management ----------*/

// Creating a new list
void createNewList(vector<TaskGroup>& groups);

/*---------- Task Management ----------*/

// Menu for selecting a task from a list to edit
int menuChooseTask(const TaskGroup& list);

// Processes editing of a task and its subtasks
void editTask(Task& task);

// Adding a new task to a list
void addTask(TaskGroup& group);

// Removing and deleting a task from a list
void removeTask(TaskGroup& task);

// Changing the name of a list
void changeListName(TaskGroup& list);

// Deleting an entire list
void deleteList(vector<TaskGroup>& groups);

#endif