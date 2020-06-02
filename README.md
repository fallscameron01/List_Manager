# List_Manager
 A console-based list-making program to help you manage your tasks.

## Features

- Ability to create and save lists.

- Ability to add tasks and subtasks.

- Ability to assign a task or subtask a priority and status.

## File Formatting for Lists

Lists are stored in text files under the folder Lists. The format of these files is below.

```
  int number of tasks
  
    string content
    short priority
    short status
  
    int number of subtasks
      string content line
      short priority
      short status
```