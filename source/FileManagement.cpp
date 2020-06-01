/*
  Programmer: Cameron Falls
  File: FileManagement.cpp
  Purpose: This file contains the definitions for file related functions.
*/

#include "FileManagement.h"

void loadLists(vector<TaskGroup>& groups)
{
  const string LIST_DIR = "Lists/";

  for (const auto& entry : fs::directory_iterator(LIST_DIR))
  {
    string filename = entry.path().u8string();
    string listname = entry.path().stem().u8string();
    TaskGroup task(filename, listname);
    groups.push_back(task);
  }

  return;
}

bool nameIsValid(const vector<TaskGroup>& groups, const string& name)
{
  for (const TaskGroup& g : groups)
  {
    if (name == g.getName())
      return false;
  }
  return true;
}