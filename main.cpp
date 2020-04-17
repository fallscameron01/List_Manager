#include "source/TaskGroup.h"
#include "source/Manager.h"

int main()
{
  vector<TaskGroup> groups;

  int listChoice = 0;
  int taskChoice = 0;

  loadLists(groups);

  while (listChoice != (groups.size() + 2)) // main loop, while quit not selected
  {
    listChoice = 0;
    taskChoice = 0;

    while (listChoice < 1 || listChoice > (groups.size() + 2)) // Selecting a list
    {
      listChoice = menuLists(groups);

      if (listChoice < 1 || listChoice > (groups.size() + 2))
        cout << "\nINVALID INPUT: Please try again." << endl;
    }

    cout << endl;

    if (listChoice < (groups.size() + 1)) // existing list
    {
      taskChoice = menuTasks(groups, listChoice);
    }
    else if (listChoice == (groups.size() + 1)) // create new list
    {

    }
  }

  return 0;
}
