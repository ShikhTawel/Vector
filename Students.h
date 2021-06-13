#ifndef CODE_STUDENTS_H
#define CODE_STUDENTS_H

#include <bits/stdc++.h>
#include "ManualVector.h"
#include "Course.h"

using namespace std;

class Students
{
private:
    string sName;
    int sID;
    string sDepartment;
public:
    Students(): sName("Ahmed"),sID(20180435),sDepartment("CS"){}    // Default Constructor
    Students(string nm,int id,string dep): sName(nm),sID(id),sDepartment(dep){}     //Constructor With Parameters
    friend istream& operator>>(istream& in,Students &s);                //Operator >> Override
    friend ostream& operator<<(ostream& out, Students s);               //Operator << Override
    ManualVector<Course> courses;              //Vector Of Courser for Each Student
    void printInfo()                        //Printing the Information of Each Student
    {
        cout<<"\nStudent Name: "<<sName<<"\n";
        cout<<"Student ID: "<<sID<<"\n";
        cout<<"Student Department: "<<sDepartment<<"\n";
        cout<<"-----------------------------------------------------------------\n";
        for(int i=0;i<courses.getSize();i++)
            cout<<courses[i]<<endl;
    }
    //The Following are Setters and Getters
    void setName(string nm)
    {
        sName=nm;
    }
    void setID(int id)
    {
        sID=id;
    }
    void setDep(string Dep)
    {
        sDepartment = Dep;
    }
    string getName()
    {
        return sName;
    }
    int getID()
    {
        return sID;
    }
    string getDep()
    {
        return sDepartment;
    }
};

istream& operator>>(istream& in, Students &s)       //Operator >> Override
{
    int num;
    cout<<"Student name: "; in>>s.sName;
    cout<<"Student ID: "; in>>s.sID;
    cout<<"Student Department: "; in>>s.sDepartment;
    cout<<"Number of Courses: "; cin>>num;
    for(int i=0;i<num;i++)
    {
        Course c;
        cout<<"Enter Course #"<<i+1<<" info: \n";
        cin>>c;
        s.courses.push_Back(c);
    }
    return in;
}

ostream& operator<<(ostream& out, Students s)       //Operator << Override
{
    s.printInfo();
    return out;
}

#endif //CODE_STUDENTS_H
