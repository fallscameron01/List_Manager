#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;
using std::getline;

#include <fstream>
using std::istream;
using std::ifstream;

#include "Status.h"

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

    string getContent() { return m_content; }
    void setContent(string content) { m_content = content; }
    
    short getPriority() { return m_priority; }
    void setContent(short priority) { m_priority = priority; }

    Status getStatus() { return m_status; }
    void setContent(Status status) { m_status = status; }

    friend istream& operator>>(istream& in, Item item);
};

#endif // !ITEM_H
