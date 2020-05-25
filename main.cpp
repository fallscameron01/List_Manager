/*
  Programmer: Cameron Falls
  File: main.cpp
  Purpose: This file contains the program main.
*/

#include "source/TaskGroup.h"
#include "source/Manager.h"

int main()
{
  const int LINE_LENGTH = 255;

  vector<TaskGroup> groups;

  int listChoice = 0; // selected list
  int taskOption = 0; // selected menu option for tasks
  int taskChoice = 0; // selected task from a list

  loadLists(groups);

  do // main loop, while quit is not selected
  {
    listChoice = 0;
    taskOption = 0;
    taskChoice = 0;

    do // Selecting a list
    {
      listChoice = menuLists(groups);
      cin.ignore(LINE_LENGTH, '\n');

      if (listChoice < 0 || listChoice > (groups.size() + 1))
        cout << "\nINVALID INPUT: Please try again." << endl;

    } while (listChoice < 0 || listChoice > (groups.size() + 1));

    cout << endl;

    if (listChoice < groups.size()) // existing list
    {
      taskOption = menuTasks(groups[listChoice]);
      cin.ignore(LINE_LENGTH, '\n');

      switch (taskOption)
      {
        case 1: // edit task
          taskChoice = menuChooseTask(groups[listChoice]);
          if(taskChoice != groups[listChoice].getNumTasks())
            editTask(groups[listChoice].getTask(taskChoice));
          break;
        case 2: // add task
          addTask(groups[listChoice]);
          break;
        case 3: // remove task
          removeTask(groups[listChoice]);
          break;
        case 4: // change list name
          changeListName(groups, groups[listChoice]);
          break;
        case 5: // delete list
          if (confirmDelete(groups[listChoice].getName()))
          {
            groups[listChoice].deleteList();
            groups.erase(groups.begin() + listChoice);
          }
          break;
        default: // go back (case 6)
          break;
      }
    }
    else if (listChoice == (groups.size())) // create new list
    {
      createNewList(groups);
    }

    for (TaskGroup t : groups) // save all lists
    {
      t.saveList();
    }

  } while (listChoice != (groups.size() + 1));

  return 0;
}
