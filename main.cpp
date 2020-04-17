#include "source/TaskGroup.h"
#include "source/Manager.h"

int main()
{
  vector<TaskGroup> groups;

  int listChoice = 0;

  loadLists(groups);

  while (listChoice < 1 || listChoice >(groups.size() + 1))
  {
    listChoice = menuLists(groups);

    if (listChoice < 1 || listChoice >(groups.size() + 1))
      cout << "\nINVALID INPUT: Please try again." << endl;
  }

  return 0;
}
