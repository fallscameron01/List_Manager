/*
  Programmer: Cameron Falls
  File: Manager.cpp
  Purpose: This file contains function implementations for functions for use managing list from main.
*/

#include "Manager.h"

void loadLists(vector<TaskGroup>& groups)
{
  const string LIST_DIR = "Lists/";

  for (const auto& entry : fs::directory_iterator(LIST_DIR))
  {
    string filename = entry.path().u8string();
    string listname = entry.path().stem().u8string();
    TaskGroup task(filename, listname);
    groups.push_back(task);
  }
  
  return;
}

bool nameIsValid(const vector<TaskGroup>& groups, const string& name)
{
  for (const TaskGroup& g : groups)
  {
    if (name == g.getName())
      return false;
  }
  return true;
}

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

void editTask(Task& task)
{
  const int MIN_OPTION = 1;
  const int MAX_OPTION = 5;

  const int LINE_LENGTH = 255;

  const int MIN_SUB = 1;

  const int MIN_SUB_OPTION = 1;
  const int MAX_SUB_OPTION = 4;

  int option = 0;
  char continueEdit = 'm';

  int subOption = 0;
  int subNumber = 0;
  int max_sub = task.getNumSubtasks();
  
  string content;
  short priority;
  Status status;

  do
  {
    option = 0;
    continueEdit = 'm';
    subOption = 0;
    subNumber = 0;
    max_sub = task.getNumSubtasks();

    cout << "\t---- Selected Task ----" << endl;
    cout << task << endl << endl;

    cout << "\t----- Options -----" << endl;
    cout << "1. Edit Content" << endl;
    cout << "2. Edit Priority" << endl;
    cout << "3. Edit Status" << endl;
    cout << "4. Edit Subtasks" << endl;
    cout << "5. Cancel" << endl;

    do
    {
      cout << "Choose an option: ";
      cin >> option;
    
      if (option < MIN_OPTION || option > MAX_OPTION)
        cout << "INVALID INPUT: Please try again." << endl;
    } while (option < MIN_OPTION || option > MAX_OPTION);

    cin.ignore(LINE_LENGTH, '\n');

    switch (option)
    {
      case 1: // Edit Content
        cout << "Enter new content: ";
        getline(cin, content);
        task.setContent(content);
        break;

      case 2: // Edit Priority
        cout << "Enter Priority: ";
        cin >> priority;
        task.setPriority(priority);
        break;

      case 3: // Edit Status
        printAssociations();
        cout << "Enter Status (0-4): ";
        cin >> status;
        task.setStatus(status);
        break;

      case 4: // Edit Subtasks
        cout << "\n\t----- Options -----" << endl;
        cout << "1. Edit Subtask" << endl;
        cout << "2. Add Subtask" << endl;
        cout << "3. Remove Subtask" << endl;
        cout << "4. Cancel" << endl;

        do
        {
          cout << "Enter the option: ";
          cin >> subOption;
          if (subOption < MIN_SUB_OPTION || subOption > MAX_SUB_OPTION)
            cout << "INVALID INPUT: Please try again." << endl;
        } while (subOption < MIN_SUB_OPTION || subOption > MAX_SUB_OPTION);

        while ((subOption != 2 && subOption != 4) && (subNumber < MIN_SUB || subNumber > max_sub))
        {
          cout << "Enter the number of the subtask (" << MIN_SUB << " - " << max_sub << ") : ";
          cin >> subNumber;
          if (subNumber < MIN_SUB || subNumber > max_sub)
            cout << "INVALID INPUT: Please try again." << endl;
        }
        subNumber--; // remove 1 for index accessing

        cin.ignore(LINE_LENGTH, '\n');
        cout << endl;

        switch (subOption)
        {
          case 1: // edit subtask
            editSubtask(task.getSubtask(subNumber));
            break;
          case 2: // add subtask
            task.push_subtask(createSubtask());
            break;
          case 3: // remove subtask
            task.pop_subtask(subNumber);
            break;
          case 4: // cancel
            continueEdit = 'y';
            break;
        }
        break;

      case 5: // Cancel
        continueEdit = 'n';
        break;
    }

    while (continueEdit != 'n' && continueEdit != 'y')
    {
      cout << "Continue editing this task? (y/n) ";
      cin >> continueEdit;

      if (continueEdit != 'n' && continueEdit != 'y')
        cout << "INVALID INPUT: Please try again." << endl;
    }
    
  } while (continueEdit == 'y');

  return;
}

Item createSubtask()
{
  Item newSub;

  string content;
  short priority;
  Status status;

  cout << "Enter content for the new subtask: ";
  getline(cin, content);

  cout << "Enter the priority of the new subtask: ";
  cin >> priority;

  cout << endl;
  printAssociations();
  cout << "Enter the status of the new subtask: ";
  cin >> status;

  newSub.setContent(content);
  newSub.setPriority(priority);
  newSub.setStatus(status);

  return newSub;
}

void editSubtask(Item& subtask)
{
  const int LINE_LENGTH = 255;

  const int MIN_OPTION = 1;
  const int MAX_OPTION = 4;

  int option = 0;

  char continueEdit = 'm';

  string content;
  short priority;
  Status status;

  do
  {
    option = 0;
    continueEdit = 'm';

    cout << "\t------ Selected Subtask ------" << endl;
    cout << subtask << endl;

    cout << "\t------ Options ------" << endl;
    cout << "1. Edit Content" << endl;
    cout << "2. Edit Priority" << endl;
    cout << "3. Edit Status" << endl;
    cout << "4. Cancel" << endl;

    do
    {
      cout << "Enter the option: ";
      cin >> option;

      if (option < MIN_OPTION || option > MAX_OPTION)
        cout << "INVALID INPUT: Please try again." << endl;
    } while (option < MIN_OPTION || option > MAX_OPTION);

    cin.ignore(LINE_LENGTH, '\n');
    cout << endl;
    switch (option)
    {
      case 1: // Edit Content
        cout << "Enter new content: ";
        getline(cin, content);
        subtask.setContent(content);
        break;

      case 2: // Edit Priority
        cout << "Enter Priority: ";
        cin >> priority;
        subtask.setPriority(priority);
        break;

      case 3: // Edit Status
        printAssociations();
        cout << "Enter Status: ";
        cin >> status;
        subtask.setStatus(status);
        break;
      case 4: // Cancel
        continueEdit = 'n';
        break;
    }
    
    while (continueEdit != 'n' && continueEdit != 'y')
    {
      cout << "Continue editing this subtask? (y/n) ";
      cin >> continueEdit;

      if (continueEdit != 'n' && continueEdit != 'y')
        cout << "INVALID INPUT: Please try again." << endl;
    }
    cout << endl;
  } while (continueEdit == 'y');
}

void addTask(TaskGroup& group)
{
  const int LINE_LENGTH = 255;

  Task newTask;

  string content;

  short priority;
  Status status;

  int numSubtasks;
  
  cout << "Enter the content of the new task: ";
  getline(cin, content);
  
  cout << "Enter the priority: ";
  cin >> priority;
  
  cout << endl;
  printAssociations();
  cout << "Enter the status: ";
  cin >> status;

  newTask.setContent(content);
  newTask.setPriority(priority);
  newTask.setStatus(status);

  cout << "Enter the number of subtasks: ";
  cin >> numSubtasks;
  
  for (int i = 0; i < numSubtasks; i++)
  {
    Item subtask;

    cin.ignore(LINE_LENGTH, '\n');
    cout << "Enter the content of subtask " << i << ": ";
    getline(cin, content);

    cout << "Enter the priority of subtask " << i << ": ";
    cin >> priority;

    cout << endl;
    printAssociations();
    cout << "Enter the status of subtask " << i << ": ";
    cin >> status;

    subtask.setContent(content);
    subtask.setPriority(priority);
    subtask.setStatus(status);

    newTask.push_subtask(subtask);
  }

  group.push_task(newTask);

  return;
}

void removeTask(TaskGroup& list)
{
  const int MIN_INPUT = 1;
  const int MAX_INPUT = list.getNumTasks() + 1;

  int input;

  cout << "\t----- TASKS -----" << endl;
  for (int i=MIN_INPUT; i<MAX_INPUT; i++)
  {
    cout << i << ". " << list.getTask(i-1);
  }
  cout << endl;

  do
  {
    cout << "Enter the number of the task you want to remove or " << MAX_INPUT << " to cancel: ";
    cin >> input;
    if (input < MIN_INPUT || input > MAX_INPUT)
      cout << "INVALID INPUT: Please try again." << endl;
  } while (input < MIN_INPUT || input > MAX_INPUT);

  if (input != MAX_INPUT)
  {
    list.pop_task(input - 1);
  }

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
