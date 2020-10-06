//
// Created by Anik on 10/6/2020.
//

#include "Student.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Student::Student(int studentID) :studentID(studentID) {}

Student::Student(int studentID, short numberOfCourses)  : studentID(studentID){
    for (short i = 0; i < numberOfCourses; i++){
        addCourse();
    }
}

int Student::getNumberOfCourses() const {
    return courseList.size();
}

void Student::addCourse() {
    Course proxy;
    double proxyValue;

    cout<<"Enter course cradit : ";
//    cin.ignore();
    cin >> proxyValue;
    proxy.setCradit(proxyValue);

    cout<<"Enter course result : ";
//    cin.ignore();
    cin >> proxyValue;
    proxy.setResult(proxyValue);

    courseList.push_back(proxy);
}

void Student::addCourse(const Course& proxy) {
    courseList.push_back(proxy);
}

void Student::showMyCourses() {
    cout<<"Student ID. : "<<studentID<<"\n";
    for(int i = 0; i < getNumberOfCourses(); i++){
        cout<<"\nCourse no. "<<i+1<<" :\n";
        courseList.at(i).showCourseDetails();
    }
}

double  Student::CalculateCGPA() {
    if(getNumberOfCourses() == 0){
        return 0.00;
    }
    double CGPA;
    double allCradit{0.00};
    double earnedCradit{0.00};
    for(int i = 0; i < getNumberOfCourses(); i++){
        earnedCradit +=(double) courseList.at(i).getCradit() * courseList.at(i).getResult();
        allCradit +=(double) courseList.at(i).getCradit();
    }
    CGPA = (double ) earnedCradit/allCradit;
    return CGPA;
}

int Student::getStudentId() const {
    return studentID;
}

void Student::setStudentId(int studentId) {
    studentID = studentId;
}
