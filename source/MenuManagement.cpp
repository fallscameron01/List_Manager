/*
  Programmer: Cameron Falls
  File: MenuManagement.cpp
  Purpose: This file contains the definitions for functions related to displaying menus.
*/

#include "MenuManagement.h"

int menuLists(const vector<TaskGroup>& groups)
{
  const int NUM_LISTS = groups.size();
  int choice = 0;

  cout << "\n\t---------- Lists ----------" << endl;
  for (int i = 0; i < NUM_LISTS; i++)
  {
    cout << (i + 1) << ". " << groups[i].getName() << endl;
  }
  cout << (NUM_LISTS + 1) << ". Create a new list." << endl;
  cout << (NUM_LISTS + 2) << ". Quit." << endl;
  cout << "\nEnter the number of the list you wish to edit or " << (NUM_LISTS + 1) << " to create a new list or " << (NUM_LISTS + 2) << " to quit: ";
  cin >> choice;

  return choice - 1; // subtract 1 to make easier to index
}

int menuTasks(const TaskGroup& list)
{
  const int MIN_CHOICE = 1;
  const int MAX_CHOICE = 7;

  int choice = 0;

  cout << list << endl;

  cout << "\t---------- Options ----------" << endl;
  cout << "1. Edit a task." << endl;
  cout << "2. Add a task." << endl;
  cout << "3. Remove a task." << endl;
  cout << "4. Change list name." << endl;
  cout << "5. Delete the list." << endl;
  cout << "6. Go back to list selection." << endl;

  while (choice < MIN_CHOICE || choice > MAX_CHOICE)
  {
    cout << "\nEnter the number of the option you want to choose: ";
    cin >> choice;

    if (choice < MIN_CHOICE || choice > MAX_CHOICE)
      cout << "\nINVALID INPUT: Please try again." << endl;
  }

  cout << endl;
  return choice;
}

int menuChooseTask(const TaskGroup& list)
{
  const int MIN_CHOICE = 1;
  const int NUM_TASKS = list.getNumTasks();

  int choice = 0;

  do
  {
    list.printTasks();
    cout << (NUM_TASKS + 1) << ". Cancel" << endl;
    cout << "\nEnter the number of the task you wish to edit or " << (NUM_TASKS + 1) << " to cancel: ";

    cin >> choice;

    if (choice < MIN_CHOICE || choice > NUM_TASKS + 1)
      cout << "\nINVALID INPUT: Please try again." << endl;
  } while (choice < MIN_CHOICE || choice > NUM_TASKS + 1);

  cout << endl;
  return choice - 1; // subtract 1 to make easier to index
}