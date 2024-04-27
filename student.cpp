#include "student.h"

std::string to_string(DegreeProgram p) {

    if (p == DegreeProgram::NETWORK) {
        return  "NETWORK";
    }
    else if (p == DegreeProgram::SECURITY) {
        return  "SECURITY";
    }
    else {
        return "SOFTWARE";
    }
}

 Student::Student() {}
 Student::Student(string theId, string theFirstName, string theLastName, string theEmail, int theAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram theprogram){
      studentId = theId;
      firstName = theFirstName;
      lastName = theLastName;
      email = theEmail;
      age = theAge;
      daysInCourses[0] = daysInCourse1;
      daysInCourses[1] = daysInCourse2;
      daysInCourses[2] = daysInCourse3;
      program = theprogram;
    }
    
    string Student::getStudentId(){
      return studentId;
    }
    void Student::setStudentId(string id){
      studentId = id;
    }
    string Student::getFirstName(){
      return firstName;
    }
    void Student::setFirstName(string firstName){
      firstName = firstName;
    }
    string Student::getLastName(){
      return lastName;
    }
    void Student::setLstName(string lastName){
      lastName = lastName;
    }
    string Student::getEmail(){
      return email;
    }
    void Student::setEmail(string theEmail){
      email = theEmail;
    }
    int Student::getAge(){
      return age;
    }
    void Student::setAge(int theAge){
      age = theAge;
    }
    int* Student::getDays(){
      return  daysInCourses;
    }
  
    DegreeProgram Student::getProgram(){
      return  program;
    }
    void Student::setProgram(DegreeProgram theProgram){
      program = theProgram;
    }
    void Student::print(){
      cout << studentId << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\tEmail: " << email  << "\t" << "Age: " << age << "\t" << "daysInCourse: " << "{" << daysInCourses[0] << ", " << daysInCourses[1] << ", " << daysInCourses[2] << "}\t" << "Degree Program: " << to_string(program) << endl;
    }