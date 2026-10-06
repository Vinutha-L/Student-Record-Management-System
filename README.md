# Student Record Management System

A console-based Student Record Management System developed in C to practice programming fundamentals, CRUD operations, dynamic memory allocation, and file handling.

## Project Overview

This project manages student records through a menu-driven console application.

The project was developed in two versions to improve the implementation step by step.

### Version 1

Version 1 uses a fixed-size array to store student records during program execution.

It implements the basic CRUD operations:

* Add student
* Display students
* Search student
* Update student
* Delete student

The records in Version 1 are stored only in memory and are lost when the program exits.

### Version 2

Version 2 improves the system by introducing dynamic memory allocation and persistent file storage.

Improvements include:

* Dynamic memory allocation using `malloc()`
* Dynamic memory expansion using `realloc()`
* Memory deallocation using `free()`
* Binary file handling using `fopen()`, `fread()`, `fwrite()`, and `fclose()`
* Loading saved records when the program starts
* Saving records after Add, Update, and Delete operations
* Duplicate USN validation
* Persistent student records across program restarts
* Support for names and branches containing spaces

## Features

* Add student records
* Display all student records
* Search students using USN
* Update student details
* Delete student records
* Prevent duplicate USNs
* Store records using binary file handling
* Load previously saved records automatically
* Dynamically manage memory as records are added

## Concepts Practiced

* C Structures
* Functions
* Arrays
* Pointers
* Dynamic Memory Allocation
* `malloc()`
* `realloc()`
* `free()`
* File Handling
* Binary Files
* CRUD Operations
* Searching
* Array manipulation
* Input handling

## Technologies Used

* C
* GCC
* Git
* GitHub

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/Vinutha-L/Student-Record-Management-System.git
```

### 2. Navigate to Version 2

```bash
cd Student-Record-Management-System/version\ 2
```

### 3. Compile

```bash
gcc main.c -o main
```

### 4. Run

```bash
./main
```

The program creates and uses `students.dat` to store student records.

## Project Structure

```text
Student-Record-Management-System/
│
├── README.md
│
├── version1/
│   └── main.c
│
└── version 2/
    └── main.c
```

## Learning Outcome

This project helped me understand how a basic C program can evolve from simple in-memory CRUD operations into a program that uses dynamic memory and persistent storage.

The main focus of Version 2 was understanding how data can be stored in a file and loaded again when the program is restarted.

## Future Improvements

* More robust input validation
* Improved user interface
* Additional student information fields
* More advanced search options
* Migration from file storage to a database
