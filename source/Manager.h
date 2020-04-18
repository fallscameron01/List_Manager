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

bool nameIsValid(const string& name);

/*---------- Menus ----------*/

// Menu for selecting a list
int menuLists(const vector<TaskGroup>& groups);

// Menu for options on a list
int menuTasks(const vector<TaskGroup>& groups, const int choice);

/*---------- List Management ----------*/

// Creating a new list
void createNewList(vector<TaskGroup>& groups);

#endif