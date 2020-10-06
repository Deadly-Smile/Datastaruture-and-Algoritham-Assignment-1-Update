//
// Created by Anik on 10/6/2020.
//

#include <iostream>
#include "Course.h"
#include "Student.h"

bool compare(Student student1, Student student2);

using std::cin;
using std::cout;
using std::endl;
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