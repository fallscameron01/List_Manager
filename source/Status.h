/*
  Programmer: Cameron Falls
  File: Status.h
  Purpose: This file contains the enumeration Status, which represents the status of a task.
*/

#ifndef STATUS_H
#define STATUS_H

// The Status enumeration represents the status of a task.
enum Status
{
  finished = 0, // task is finished
  todo = 1, // task is to be done in the future
  inprogress = 2, // task is in progress
  upnext = 3, // the next task to start
  postponed = 4 // task has been put off
};

#endif // !STATUS_H
