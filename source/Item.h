/*
  Programmer: Cameron Falls
  File: Item.h
  Purpose: This file contains the class Item, which represents a subtask.
*/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

#include "Status.h"

using namespace std;

// The Item class represents a subtask.
class Item
{
  protected:
    string m_content; // the content of the Item, i.e. what the Item is
    short m_priority; // the priority of the Item, range of 0-10
    Status m_status; // the current status of the Item

  public:

    /*
      Description: Constructs an Item with no content, 0 priority, and 'finished' status.
    */
    Item()
      : m_content(""), m_priority(0), m_status(static_cast<Status>(0))
    { }

    /*
      Description: Returns the content of the Item.
      Returns: string - the content.
    */
    string getContent() const { return m_content; }

    /*
      Description: Sets the content of the Item.
      Parameters: content - the content.
      Returns: none.
    */
    void setContent(string content) { m_content = content; }
    
    /*
      Description: Returns the priority of the Item.
      Returns: short - the priority.
    */
    short getPriority() const { return m_priority; }

    /*
      Description: Sets the priority of the Item.
      Parameters: priority - the priority.
      Returns: none.
    */
    void setPriority(short priority) { m_priority = priority; }


    /*
      Description: Returns the status of the Item.
      Returns: Status (enum) - the status.
    */
    Status getStatus() const { return m_status; }

    /*
      Description: Sets the status of the Item.
      Parameters: status - the status.
      Returns: none.
    */
    void setStatus(Status status) { m_status = status; }

    /*
      Description: Sets the status of the Item.
      Parameters: status - the status.
      Returns: none.
    */
    void setStatus(int status) { m_status = static_cast<Status>(status); }

    /*
      Description: Outputs the given Item to the ostream.
      Parameters: out - the ostream to output to.
                  item - the Item to output.
      Returns: ostream - the given ostream.
    */
    friend ostream& operator<<(ostream& out, Item& item);
};

#endif // !ITEM_H
