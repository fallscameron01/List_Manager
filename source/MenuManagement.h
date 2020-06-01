/*
  Programmer: Cameron Falls
  File: MenuManagement.h
  Purpose: This file contains the definitions for functions related to displaying menus.
*/

#ifndef MENUMANAGEMENT_H
#define MENUMANAGEMENT_H

#include <vector>
#include <iostream>

#include "TaskGroup.h"

using namespace std;

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

/*
  Description: Displays a menu for selecting a task from a list.
  Parameters: list - the selected list.
  Returns: int - the index of the task
*/
int menuChooseTask(const TaskGroup& list);

#endif // !MENU_MANAGEMENT