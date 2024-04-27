#include <iostream>
#include <sstream>
#include <algorithm>
#include "roster.h"
vector<string> parse_line(string str) {
    vector<string> v;
    stringstream ss(str);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }
    return v;
}
int main() {
    cout << "C867 Scripting and Programming: Applications" << endl;
    cout << "Language:  C++" << endl;
    cout << "Student ID: 001523317" << endl;
    cout << "Name: Frank Arunian" << endl;
    const string studentData[] =

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Frank,Arunian,frankarunian@gmail.com,23,45,15,48,SOFTWARE"
    };

    Roster roster = Roster();
    int size = sizeof(studentData) / sizeof(studentData[0]);

    for (int i = 0; i < size; i++) {
        vector<string> v = parse_line(studentData[i]);
        string studentId = v[0], firstName = v[1], lastName = v[2], emailAddress = v[3], program = v[8];
        int age = stoi(v[4]), daysInCourse1 = stoi(v[5]), daysInCourse2 = stoi(v[6]), daysInCourse3 = stoi(v[7]);
        DegreeProgram degreeProgram;

        if (program == "SECURITY") {
            degreeProgram = DegreeProgram::SECURITY;
        }
        else if (program == "SOFTWARE") {
            degreeProgram = DegreeProgram::SOFTWARE;
        }
        else {
            degreeProgram = DegreeProgram::NETWORK;
        }
        roster.add(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }
    cout << "Displaying all students" << endl;
    roster.printAll();
    cout << "\nDisplaying invalid emails" << endl;
    roster.printInvalidEmails();
    cout << "\n" << endl;
    roster.printAverageDaysInCourse("A1");
    roster.printAverageDaysInCourse("A2");
    roster.printAverageDaysInCourse("A3");
    roster.printAverageDaysInCourse("A4");
    roster.printAverageDaysInCourse("A5");

    cout << "\nShowing students on degree program: SOFTWARE" << endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << "\nRemoving A3" << endl;
    roster.remove("A3");
    roster.printAll();
    cout << "\nRemoving A3 again" << endl;
    roster.remove("A3");
    cout << "\nDONE." << endl;
}