#include "source/TaskGroup.h"
#include "source/Manager.h"

int main()
{
  const int LINE_LENGTH = 256;

  vector<TaskGroup> groups;

  int listChoice = 0;
  int taskChoice = 0;

  loadLists(groups);

  do // main loop, while quit is not selected
  {
    listChoice = 0;
    taskChoice = 0;

    do// Selecting a list
    {
      listChoice = menuLists(groups);
      cin.ignore(LINE_LENGTH, '\n');

      if (listChoice < 1 || listChoice > (groups.size() + 2))
        cout << "\nINVALID INPUT: Please try again." << endl;

    } while (listChoice < 1 || listChoice >(groups.size() + 2));

    cout << endl;

    if (listChoice < (groups.size() + 1)) // existing list
    {
      taskChoice = menuTasks(groups, listChoice);
      cin.ignore(LINE_LENGTH, '\n');
    }
    else if (listChoice == (groups.size() + 1)) // create new list
    {
      createNewList(groups);
    }

  } while (listChoice != (groups.size() + 2));

  return 0;
}
