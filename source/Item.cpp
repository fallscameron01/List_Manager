#include "Item.h"

istream& operator>>(istream& in, Item item)
{
  short temp;

  getline(in, item.m_content);
  in >> item.m_priority;
  in >> temp;
  item.m_status = static_cast<Status>(temp);

  return in;
}

ostream& operator<<(ostream& out, Item item)
{
  out << "\t\tTask: " << item.m_content << endl;
  out << "\t\t\tPriority: " << item.m_priority << endl;
  out << "\t\t\tStatus: " << item.m_status << endl;

  return out;
}
