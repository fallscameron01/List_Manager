/*
  Programmer: Cameron Falls
  File: Status.h
  Purpose: This file contains the enumeration Status, which represents the status of a task.
*/

#ifndef STATUS_H
#define STATUS_H

enum Status
{
  finished = 0,
  todo = 1,
  inprogress = 2,
  upnext = 3,
  postponed = 4
};

#endif // !STATUS_H
