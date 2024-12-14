# Student Management System

## Overview

This program is a **Student Management System** implemented in C++. It allows users to manage student records by providing functionalities to:

1. Add new student details.
2. Display all student records.
3. Search for a student by roll number.

The data is stored persistently in a text file named `students.txt`.

## Features

1. **Add Student**: Enter student details (name, roll number, and marks) and save them to a file.
2. **Display All Students**: Retrieve and display all student records from the file.
3. **Search by Roll Number**: Search for a student by their roll number and display their details if found.

## File Structure

The program reads and writes student data to a file called `students.txt`. Each student's data is stored in the following format:

```
<Roll Number>
<Name>
<Marks>
```

## How to Run

1. **Prerequisites**:
   - Install a C++ compiler (e.g., GCC or MSVC).
   - Ensure you have a terminal or command-line interface for running the program.

2. **Compilation**:
   Compile the program using the following command:
   ```
   g++ -o student-management-system student-management-system.cpp
   ```

3. **Execution**:
   Run the program with:
   ```
   ./student-management-system
   ```

4. **Using the Program**:
   - Follow the on-screen menu to interact with the program.
   - Enter your choice to perform actions like adding a student, displaying records, or searching by roll number.

## Menu Options

1. **Add Student**:
   - Enter the student's name, roll number, and marks.
   - The data is appended to `students.txt`.

2. **Display All Students**:
   - Displays all student details from the file.
   - Outputs a message if no records are found.

3. **Search by Roll Number**:
   - Enter a roll number to search for a student.
   - Displays student details if the roll number exists; otherwise, shows an appropriate message.

4. **Exit**:
   - Terminates the program.

## Example Usage

1. **Adding a Student**
```
Enter the name: Alice
Enter the roll number: 102
Enter the marks: 88.5
Student added successfully!
```

2. **Displaying All Students**
```
Roll Number: 101
Name: Kunal
Marks: 95.5
**************************************************
Roll Number: 102
Name: Aman
Marks: 88.5
**************************************************
```

3. **Searching by Roll Number**


- **When Found:**
```
Enter Roll Number to search: 102
Student Found:
Roll Number: 102
Name: Alice
Marks: 88.5
```

- **When Not Found:**
```
Enter Roll Number to search: 103
Student with roll number 103 does not exist.
```

## Code Highlights

- **Class Design**:
  - `Student`: Encapsulates the student details and provides methods for input, display, file save/load operations.

- **File Handling**:
  - Uses `ofstream` for writing and `ifstream` for reading from `students.txt`.

- **Input Validation**:
  - Basic validation is performed to ensure inputs are correctly entered.
