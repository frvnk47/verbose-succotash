#pragma once
#ifndef STUDENT
#define STUDENT
#include <iostream>
#include "degree.h"
using namespace std;
class Student {
private:
    string studentId;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourses[3];
    DegreeProgram program;
public:
    Student();
    Student(string theId, string theFirstName, string theLastName, string theEmail, int theAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program);
    string getStudentId();
    void setStudentId(string id);
    string getFirstName();
    void setFirstName(string firstName);
    string getLastName();
    void setLstName(string lastName);
    string getEmail();
    void setEmail(string email);
    int getAge();
    void setAge(int age);
    int* getDays();
    DegreeProgram getProgram();
    void setProgram(DegreeProgram program);
    void print();
};
#endif //STUDENT