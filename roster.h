#ifndef ROSTER
#define ROSTER
#include <iostream>
#include <vector>
#include "student.h"
using namespace std;
class Roster {
public:
    Student classRosterArray[100];
    int size = 0;
    Roster();
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif //ROSTER