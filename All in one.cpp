//
// Created by Anik on 10/6/2020.
//

#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

class Course {
private:
    double cradit;
    double result;
public:
    Course(double cradit, double result);

    Course();

    void showCourseDetails() const;

    double getCradit() const;

    void setCradit(double courseCradit);

    double getResult() const;

    void setResult(double courseResult);
};

Course::Course(double cradit, double result)
        : cradit(cradit), result(result) {}

Course::Course() {
    cradit = 0.00;
    result = 0.00;
}

double Course::getCradit() const {
    return cradit;
}

void Course::setCradit(double courseCradit) {
    Course::cradit = courseCradit;
}

double Course::getResult() const {
    return result;
}

void Course::setResult(double courseResult) {
    Course::result = courseResult;
}

void Course::showCourseDetails() const {
    cout<<"Cradit : "<<cradit<<"\n"
        <<"Result : "<<result<<endl;
}

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

bool compare(Student student1, Student student2);

int main() {
    int numberOfStudent{0};
    cout<<"Enter the number of student : ";
    cin>>numberOfStudent;
    std::vector<Student> Class;

    for(int i = 0; i < numberOfStudent; i++){
        int proxyID{0};
        short numberOfCourse{0};

        cout<<"Enter the student ID. : ";
        cin >> proxyID;
        Student proxyStudent(proxyID);

        cout<<"Enter the number of course : ";
        cin>>numberOfCourse;

        for(int j = 0; j < numberOfCourse; j++){
            proxyStudent.addCourse();
        }

        Class.push_back(proxyStudent);
    }

    std::sort(Class.begin(),Class.end(),compare);
    cout<<"The marit list of class by CGPA :\n"
          "---------------------------------"<<endl;
    for (int i = numberOfStudent - 1; i >= 0; i--){
        cout<<numberOfStudent-i<<". Student ID. : "
        <<Class.at(i).getStudentId()<<" scored CGPA "
        <<Class.at(i).CalculateCGPA()<<endl;
    }

    return 0;
}

bool compare(Student student1, Student student2){
    return student1.CalculateCGPA() < student2.CalculateCGPA();
}
