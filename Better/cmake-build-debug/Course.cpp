//
// Created by Anik on 10/6/2020.
//

#include "Course.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

Course::Course(double cradit, double result)
        : cradit(cradit), result(result) {}

Course::Course() {
    cradit = 0.00;
    result = 0.00;
}

double Course::getCradit() const {
    return cradit;
}

void Course::setCradit(double cradit) {
    Course::cradit = cradit;
}

double Course::getResult() const {
    return result;
}

void Course::setResult(double result) {
    Course::result = result;
}

void Course::showCourseDetails() {
    cout<<"Cradit : "<<cradit<<"\n"
        <<"Result : "<<result<<endl;
}