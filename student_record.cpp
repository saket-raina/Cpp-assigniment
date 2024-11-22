#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void printlines() {
    for (int i = 0; i < 40; i++)
        cout << "-";
    cout << endl;
}

class student {
private:
    string name;
    string age;
    string semester;
    int roll_no;
    int registration_no;
    string parentage;
    int attendance;
    int marks[5];
    float marks_percentage;
    float attendance_percentage;

public:
    void get_details() {
        static int num = 1;
        cout << endl;
        printlines();
        cout << "Details of Student " << num << " : " << endl;
        printlines();
        num++;

        cout << "Enter Name : ";
        cin >> name;
        cout << "Enter Age : ";
        cin >> age;
        cout << "Enter Semester : ";
        cin >> semester;
        cout << "Enter Roll Number : ";
        cin >> roll_no;
        cout << "Enter Registration Number : ";
        cin >> registration_no;
        cout << "Enter Parentage : ";
        cin.ignore();
        getline(cin, parentage);

        do {
            cout << "Enter the number of C++ classes attended (out of 30) : ";
            cin >> attendance;
            if (attendance < 0 || attendance > 30)
                cout << "Invalid input! Please enter a value between 0 and 30." << endl;
        } while (attendance < 0 || attendance > 30);

        cout << "Subject Marks(out of 100)" << endl;
        for (int i = 0; i < 5; i++) {
            do {
                cout << "Enter the marks of subject " << i+1 << " : ";
                cin >> marks[i];
                if (marks[i] < 0 || marks[i] > 100)
                    cout << "Invalid input! Marks should be between 0 and 100." << endl;
            } while (marks[i] < 0 || marks[i] > 100);
        }
    }

    void show_details() const {
        cout << endl;
        printlines();
        cout << "Showing Student's Details" << endl;
        printlines();
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Semester : " << semester << endl;
        cout << "Roll Number : " << roll_no << endl;
        cout << "Registration Number : " << registration_no << endl;
        cout << "Parentage : " << parentage << endl;
        float attendance_percentage = (attendance / 30.0) * 100.0;
        cout << "Attendance : " << attendance_percentage << "%" << endl;

        cout << "Subject Marks" << endl;
        for (int i = 0; i < 5; i++)
            cout << "Marks of subject " << i+1 << " : " << marks[i] << endl;
    }

    float get_attendance_percentage() const {
        return (attendance / 30.0) * 100.0;
    }
   
    void calculate_percentage() {
        int total = 0;
        for (int i = 0; i < 5; i++)
            total += marks[i];
        marks_percentage = (total / 500.0) * 100;
    }

    float get_marks_percentage() const {
        return marks_percentage;
    }

    string get_name() const {
        return name;
    }

    void print_attendence() const {
        cout << endl << "Showing Attendance Details" << endl;
        printlines();
        cout << "Attendance of " << name << " is " << get_attendance_percentage() << "%" << endl;
    }

    void print_shortage(student arrstudent[], int total_students) const {
        bool shortage_found = false;
        cout << endl << "Shortage Cases are " << endl;
        printlines();
        for (int i = 0; i < total_students; i++) {
            if (arrstudent[i].get_attendance_percentage() < 75) {
                cout << arrstudent[i].get_name() << " with " << arrstudent[i].get_attendance_percentage() << "% attendance" << endl;
                shortage_found = true;
            }
        }
        if (!shortage_found) {
            cout << "No such Student" << endl;
        }
    }

    void show_toppers(student arrstudent[], int total_students) {
        for (int i = 0; i < total_students; i++)
            arrstudent[i].calculate_percentage();

        sort(arrstudent, arrstudent + total_students, [](const student& a, const student& b) {
            return a.get_marks_percentage() > b.get_marks_percentage();
        });

        bool topper_found = false;
        cout << endl << "Top 5 Students" << endl;
        printlines();
        for (int i = 0; i < min(total_students, 5); i++) {
            if (arrstudent[i].get_marks_percentage() >= 90) {
                cout << arrstudent[i].get_name() << " - " << arrstudent[i].get_marks_percentage() << "%" << endl;
                topper_found = true;
            }
        }
        if (!topper_found) {
            cout << "No such student" << endl;
        }
    }

    void show_above_90(student arrstudent[], int total_students) {
        cout << endl << "Students with Marks and Attendance >= 90%" << endl;
        printlines();
        bool found = false;
        for (int i = 0; i < total_students; i++) {
            if (arrstudent[i].get_marks_percentage() >= 90 && arrstudent[i].get_attendance_percentage() >= 90) {
                cout << arrstudent[i].get_name() << " - Marks: " << arrstudent[i].get_marks_percentage() << "%, Attendance: " << arrstudent[i].get_attendance_percentage() << "%" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No such student" << endl;
        }
    }
};

int main() {
    int total_students = 0;
    cout << "Enter the total number of students: ";
    cin >> total_students;
    student *arrstudent = new student [total_students];

    for (int i = 0; i < total_students; i++) {
        arrstudent[i].get_details();
        arrstudent[i].show_details();
    }

    arrstudent[0].show_toppers(arrstudent, total_students);
    arrstudent[0].print_shortage(arrstudent, total_students);
    arrstudent[0].show_above_90(arrstudent, total_students);

    delete[] arrstudent;
    
    return 0;
}
