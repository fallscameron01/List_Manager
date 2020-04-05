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
