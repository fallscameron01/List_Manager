/*
  Programmer: Cameron Falls
  File: Status.h
  Purpose: This file contains the enumeration Status, which represents the status of a task. It also contains
           operator overload definitions for Status.
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

/*
  Desciprtion: Outputs the associations of each status and corresponding integer.
  Returns: none.
*/
void printAssociations();

/*
  Description: Outputs the given Status to the ostream. The output is a string describing the enumeration state.
  Parameters: out - the ostream to output to.
              status - the Status to output.
  Returns: ostream - the given ostream.
*/
ostream& operator<<(ostream& out, const Status& status);

/*
  Description: Takes input from the given istream to a Status.
  Parameters: in - the istream to take input from.
              s - the status to store the input in.
  Returns: istream - the given istream.
*/
istream& operator>>(istream& in, Status& s);

#endif // !STATUS_H
