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

  return choice;
}

int menuTasks(const vector<TaskGroup>& groups, const int listNum)
{
  const int MIN_CHOICE = 1;
  const int MAX_CHOICE = 7;

  int choice = 0;

  cout << groups[listNum-1] << endl;

  cout << "\t---------- Options ----------" << endl;
  cout << "1. View a task." << endl;
  cout << "2. Edit a task." << endl;
  cout << "3. Add a task." << endl;
  cout << "4. Remove a task." << endl;
  cout << "5. Change list Name." << endl;
  cout << "6. Delete the list." << endl;
  cout << "7. Go back to list selection." << endl;
  
  while (choice < MIN_CHOICE || choice > MAX_CHOICE)
  {
    cout << "\nEnter the number of the option you want to choose: ";
    cin >> choice;

    if (choice < MIN_CHOICE || choice > MAX_CHOICE)
      cout << "\nINVALID INPUT: Please try again." << endl;
  }
  
  return choice;
}
