#ifndef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <experimental/filesystem>
#include <vector>
#include <string>

#include "TaskGroup.h"

namespace fs = std::experimental::filesystem;
using namespace std;

/*
  Description: Loads all lists in the directory Lists/ into groups.
  Parameters: groups - holds the loaded lists
  Returns: none.
*/
void loadLists(vector<TaskGroup>& groups);

/*
  Description: Checks if a list name is valid.
  Parameters: groups - all the lists, to check if the name is already in use.
              name - the name being checked.
  Returns: bool - whether or not the name is valid.
*/
bool nameIsValid(const vector<TaskGroup>& groups, const string& name);

#endif