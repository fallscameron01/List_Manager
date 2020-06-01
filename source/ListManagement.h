/*
  Programmer: Cameron Falls
  File: ListManagement.h
  Purpose: This file contains the definitions for list-related functions.
*/

#ifndef LISTMANAGEMENT_H
#define LISTMANAGEMENT_H

#include <vector>
#include <iostream>
#include <string>

#include "FileManagement.h"
#include "TaskGroup.h"

using namespace std;

/*
  Description: Displays prompts for creating a new list.
  Parameters: gropups - the group of lists
  Returns: none.
*/
void createNewList(vector<TaskGroup>& groups);

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

#endif // !LISTMANAGEMENT_H