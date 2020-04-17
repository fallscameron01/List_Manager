#ifndef MANAGER_H
#define MANAGER_H

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include <experimental/filesystem>
#include <vector>
#include <string>
#include <iostream>

#include "TaskGroup.h"

namespace fs = std::experimental::filesystem;

using namespace std;

// loads all the lists in the directory
void loadLists(vector<TaskGroup>& groups);

#endif