/*
  Programmer: Cameron Falls
  File: Item.cpp
  Purpose: This file contains the function implementations of the class Item, which represents a subtask.
*/

#include "Item.h"

/*---------- Item Friend Functions ----------*/

ostream& operator<<(ostream& out, Item& item)
{
  out << "\t\tTask: " << item.m_content << endl;
  out << "\t\t\tPriority: " << item.m_priority << endl;
  out << "\t\t\tStatus: " << item.m_status << endl;

  return out;
}
