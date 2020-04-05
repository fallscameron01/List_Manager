#ifndef TASK_H
#define TASK_H

#include <vector>
using std::vector;

#include "Item.h"

class Task :
  public Item
{
  private:
    vector<Item> m_subtasks;
  public:
    friend istream& operator>>(istream& in, Task task);
};

#endif // !TASK_H
