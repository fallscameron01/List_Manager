#include "ListManagement.h"

void createNewList(vector<TaskGroup>& groups)
{
  string name = "";
  string filename = "";
  bool validName = false;

  do
  {
    cout << "Enter the name for your new list or type \'quit\' to cancel: ";
    getline(cin, name);

    validName = nameIsValid(groups, name);

    if (!validName) // invalid name
      cout << "INVALID NAME: Make sure the name is not already in use!" << endl;
    else if (name != "quit") // not quit
    {
      cout << "Your list has been created. Select it below to add tasks." << endl;
      filename = name + ".txt";
      groups.push_back(TaskGroup(filename, name));
    }
  } while (name != "quit" && !validName);

  return;
}

void changeListName(const vector<TaskGroup>& groups, TaskGroup& list)
{
  string name = "";
  do
  {
    cout << "Enter the new name for the list: ";
    getline(cin, name);
    if (!nameIsValid(groups, name))
      cout << "NAME IS INVALID (ALREADY IN USE): Please try again." << endl;
  } while (!nameIsValid(groups, name));

  list.setName(name);

  return;
}

bool confirmDelete(string listName)
{
  char option = 'n';

  do
  {
    cout << "Are you sure you want to delete " << listName << " (y/n) ? THIS CANNOT BE UNDONE: ";
    cin >> option;
    if (option != 'n' && option != 'y')
      cout << "INVALID INPUT: Please try again." << endl;
  } while (option != 'n' && option != 'y');

  return (option == 'y' ? true : false);
}
