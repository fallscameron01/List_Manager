#ifndef ITEM_H
#define ITEM_H

#include <string>
using std::string;

#include "Status.h"

class Item
{
  protected:
    string m_content;
    short m_priority;
    Status m_status;
  public:
    string getContent() { return m_content; }
    void setContent(string content) { m_content = content; }
    
    short getPriority() { return m_priority; }
    void setContent(short priority) { m_priority = priority; }

    Status getStatus() { return m_status; }
    void setContent(Status status) { m_status = status; }
};

#endif // !ITEM_H
