#include "source/TaskGroup.h"
#include "source/Manager.h"

int main()
{
  vector<TaskGroup> groups;

  loadLists(groups);

  for (auto& g : groups)
    cout << g << endl;

  return 0;
}
