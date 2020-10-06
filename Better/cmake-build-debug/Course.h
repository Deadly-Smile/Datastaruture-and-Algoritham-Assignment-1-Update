//
// Created by Anik on 10/6/2020.
//

#ifndef BEFORE_COURSE_H
#define BEFORE_COURSE_H


class Course {
private:
    double cradit;
    double result;
public:
    Course(double cradit, double result);

    Course();

    void showCourseDetails();

    double getCradit() const;

    void setCradit(double cradit);

    double getResult() const;

    void setResult(double result);
};


#endif //BEFORE_COURSE_H
