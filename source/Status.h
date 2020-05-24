/*
  Programmer: Cameron Falls
  File: Status.h
  Purpose: This file contains the enumeration Status, which represents the status of a task.
*/

#ifndef STATUS_H
#define STATUS_H

#include <iostream>
#include <string>

using namespace std;

// The Status enumeration represents the status of a task.
enum Status
{
  FINISHED = 0, // task is finished
  TODO = 1, // task is to be done in the future
  IN_PROGRESS = 2, // task is in progress
  UP_NEXT = 3, // the next task to start
  POSTPONED = 4 // task has been put off
};

ostream& operator<<(ostream& out, const Status& status);

istream& operator>>(istream& in, Status& s);

#endif // !STATUS_H
