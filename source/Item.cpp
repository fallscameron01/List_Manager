#include "Item.h"

ostream& operator<<(ostream& out, Item& item)
{
  out << "\t\tTask: " << item.m_content << endl;
  out << "\t\t\tPriority: " << item.m_priority << endl;
  out << "\t\t\tStatus: " << item.m_status << endl;

  return out;
}
