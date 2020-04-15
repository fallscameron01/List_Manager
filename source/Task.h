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
    void push_subtask(const Item& subtask);

    friend ostream& operator<<(ostream& out, Task& task);
};

#endif // !TASK_H
