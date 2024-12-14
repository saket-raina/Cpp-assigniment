#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:
    void inputDetails() 
    {   
        cout << endl;
        cin.ignore();
        cout << "Enter the name: ";
        getline(cin, name);
        cout << "Enter the roll number: ";
        cin >> rollNo;
        cout << "Enter the marks: ";
        cin >> marks;
    }

    void displayDetails() const 
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }

    void saveToFile(ofstream &outFile) const 
    {
        outFile << rollNo << '\n' << name << '\n' << marks << '\n';
    }

    void loadFromFile(ifstream &inFile) 
    {
        inFile >> rollNo;
        inFile.ignore();
        getline(inFile, name);
        inFile >> marks;
        inFile.ignore();
    }

    int getRollNo() const 
    {
        return rollNo;
    }
};

// Add Student Function
void addStudent(const string &filename) 
{
    Student student;
    student.inputDetails();

    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) 
    {
        student.saveToFile(outFile);
        outFile.close();
        cout << "Student added successfully!" << endl;
    }
    else{
        cout << "File cannot be accessed or created." << endl;
        }
}

// Display All Students
void displayAllStudents(const string &filename) 
{
    ifstream inFile(filename);
    cout << endl;
    if (inFile.is_open()) 
    {
        Student student;
        bool found = false;
        while (inFile.peek() != EOF)
        {
            student.loadFromFile(inFile);
            student.displayDetails();
            cout << string(50, '*') << endl;
            found = true;
        }
        inFile.close();
          if (!found)
          {
            cout << "No students found!" << endl;
          }
    }
    else{
         cout << "File cannot be accessed." << endl;
        }
}

// Search Student by Roll No
void searchStudentByRollNo(const string &filename, int rollNo) 
{
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        Student student;
        bool found = false;
        while (inFile.peek() != EOF)
        {
            student.loadFromFile(inFile);
            if (student.getRollNo() == rollNo)
            {
                cout << "Student Found:" << endl;
                student.displayDetails();
                found = true;
                break;
            }
        }
        inFile.close();
        if (!found) {
            cout << "Student with roll number " << rollNo << " does not exist." << endl;
        }
    }
    else{
         cout << "File cannot be accessed." << endl;
        }
}

int main() 
{
    const string filename = "students.txt";
    int choice;

    do {
        cout << endl << "Student Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            addStudent(filename);
            break;
        case 2:
            displayAllStudents(filename);
            break;
        case 3: 
            {
            int rollNo;
            cout << endl << "Enter Roll Number to search: ";
            cin >> rollNo;
            searchStudentByRollNo(filename, rollNo);
            break;
            }
        case 4:
            cout << "Exited the program." << endl;
            break;
        default:
            cout << "Invalid choice." << endl << "Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
