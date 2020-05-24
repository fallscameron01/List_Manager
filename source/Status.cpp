/*
  Programmer: Cameron Falls
  File: Status.cpp
  Purpose: This file contains the function implementations of the functions defined in Status.h
*/

#include "Status.h"

ostream& operator<<(ostream& out, const Status& status)
{
  string message;
  switch (status)
  {
  case FINISHED:
    message = "finished";
    break;
  case TODO:
    message = "to do";
    break;
  case IN_PROGRESS:
    message = "in progress";
    break;
  case UP_NEXT:
    message = "up next";
    break;
  case POSTPONED:
    message = "postponed";
    break;
  }
  out << message;
  return out;
}

istream& operator>>(istream& in, Status& s)
{
  int temp;

  in >> temp;
  s = static_cast<Status>(temp);

  return in;
}