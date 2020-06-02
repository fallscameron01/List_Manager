/*
  Programmer: Cameron Falls
  File: TaskManagement.cpp
  Purpose: This file contains function definitions for functions relating to tasks.
*/

#include "TaskManagement.h"

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

        while ((subOption != 2 && subOption != 4) && (subNumber < MIN_SUB || subNumber > max_sub) && (max_sub != 0))
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
            if (max_sub != 0)
              editSubtask(task.getSubtask(subNumber));
            else
              cout << "Task contains no subtasks to edit!" << endl;
            break;
          case 2: // add subtask
            task.push_subtask(createSubtask());
            break;
          case 3: // remove subtask
            if (max_sub != 0)
              task.pop_subtask(subNumber);
            else
              cout << "Task contains no subtasks to remove!" << endl;
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
  
  printAssociations();
  cout << "Enter the status (0-4): ";
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

    printAssociations();
    cout << "Enter the status of subtask " << i << " (0-4): ";
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

  printAssociations();
  cout << "Enter the status of the new subtask (0-4): ";
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
      cout << "Enter Status (0-4): ";
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