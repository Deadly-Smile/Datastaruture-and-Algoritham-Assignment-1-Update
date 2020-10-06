//
// Created by Anik on 10/6/2020.
//

#ifndef BEFORE_STUDENT_H
#define BEFORE_STUDENT_H


#include <vector>
#include "Course.h"

class Student {
private:
    std::vector<Course> courseList;
    int studentID;
public:
    Student(int studentID);

    int getStudentId() const;

    Student(int studentID, short numberOfCourses);

    int getNumberOfCourses() const;

    void addCourse();

    void addCourse(const Course& proxy);

    void showMyCourses();

    double CalculateCGPA();

    void setStudentId(int studentId);
};


#endif //BEFORE_STUDENT_H
