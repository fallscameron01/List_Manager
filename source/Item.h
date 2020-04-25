/*
  Programmer: Cameron Falls
  File: Item.h
  Purpose: This file contains the class Item, which represents a subtask.
*/

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#include "Status.h"

// The Item class represents a subtask.
class Item
{
  protected:
    string m_content;
    short m_priority;
    Status m_status;
  public:
    Item()
      : m_content(" "), m_priority(0), m_status(static_cast<Status>(0))
    { }

    string getContent() const { return m_content; }
    void setContent(string content) { m_content = content; }
    
    short getPriority() const { return m_priority; }
    void setPriority(short priority) { m_priority = priority; }

    Status getStatus() const { return m_status; }
    void setStatus(Status status) { m_status = status; }

    friend ostream& operator<<(ostream& out, Item& item);
};

#endif // !ITEM_H
