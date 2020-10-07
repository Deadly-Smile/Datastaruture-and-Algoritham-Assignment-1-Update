
//
// Created by Anik on 10/6/2020.
//

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

class Course {
private:
    double cradit;
    double result;
public:
    Course(double cradit, double result)
        : cradit(cradit), result(result) {}

    Course(){
        cradit = 0.00;
        result = 0.00;
    }
    
    void showCourseDetails() const{
        cout<<"Cradit : "<<cradit<<"\n"
            <<"Result : "<<result<<endl;
    }
    
    double getCradit() const{
        return cradit;
    }

    void setCradit(double courseCradit){
        this->cradit = courseCradit;
    }

    double getResult() const{
        return result;
    }

    void setResult(double courseResult){
        this->result = courseResult;
    }
};

class Student {
private:
    std::vector<Course> courseList;
    int studentID;
public:
    Student(int studentID) :studentID(studentID) {}

    int getStudentId() const {
        return studentID;
    }

    Student(int studentID, short numberOfCourses) : studentID(studentID){
        for (short i = 0; i < numberOfCourses; i++){
            addCourse();
        }
    }

    int getNumberOfCourses() const {
        return courseList.size();
    }

    void addCourse() {
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


    void addCourse(const Course& proxy) {
        courseList.push_back(proxy);
    }

    void showMyCourses() {
        cout<<"Student ID. : "<<studentID<<"\n";
        for(int i = 0; i < getNumberOfCourses(); i++){
            cout<<"\nCourse no. "<<i+1<<" :\n";
            courseList.at(i).showCourseDetails();
        }
    }

    double CalculateCGPA() {
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

    void setStudentId(int studentId) {
        studentID = studentId;
    }
};

bool compare(Student student1, Student student2){
    return student1.CalculateCGPA() < student2.CalculateCGPA();
}

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
