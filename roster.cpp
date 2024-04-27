#include "roster.h"
#include <iostream>
using namespace std;
Roster::Roster() {}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    Student s = Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
    classRosterArray[size] = s;
    size++;
}

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        Student s = classRosterArray[i];
        if (s.getStudentId() == studentID) {
            found = true;
        }

        if (found) {
            classRosterArray[i] = classRosterArray[i + 1];
        }
    }
    if (found) {
        size--;
    }
    else {
        cout << "The student with ID: " << studentID << " was not found" << endl;
    }
}
void Roster::printAll() {
    for (int i = 0; i < size; i++) {
        classRosterArray[i].print();
    }
}
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < size; i++) {
        Student s = classRosterArray[i];
        if (s.getStudentId() == studentID) {
            int* days = s.getDays();
            int avg = (days[0] + days[1] + days[2]) / 3;
            cout << "Student ID: " << studentID << ", avarage days in courses is: " << avg << endl;
            return;
        }
    }
    cout << "The student with ID: " << studentID << " was not found" << endl;
}
void Roster::printInvalidEmails() {
    for (int i = 0; i < size; i++) {
        Student s = classRosterArray[i];
        string email = s.getEmail();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos) {
            cout << email << " - is invalid" << endl;
        }
    }
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < size; i++) {
        Student s = classRosterArray[i];
        if (s.getProgram() == degreeProgram) {
            s.print();
        }
    }
}
