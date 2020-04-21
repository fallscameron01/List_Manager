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
  cout << "4. Change list Name." << endl;
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

// TODO: Implement editTask()
void editTask(Task& task)
{
  return;
}

void addTask(TaskGroup& group)
{
  const int LINE_LENGTH = 255;

  Task newTask;

  string content;

  short priority;
  short tempStatus;
  Status status;

  int numSubtasks;
  
  cout << "Enter the content of the new task: ";
  getline(cin, content);
  
  cout << "Enter the priority: ";
  cin >> priority;
  
  cout << "Enter the status: ";
  cin >> tempStatus;
  status = static_cast<Status>(tempStatus);

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

    cout << "Enter the status of subtask " << i << ": ";
    cin >> tempStatus;
    status = static_cast<Status>(tempStatus);

    subtask.setContent(content);
    subtask.setPriority(priority);
    subtask.setStatus(status);

    newTask.push_subtask(subtask);
  }

  group.push_task(newTask);

  return;
}
