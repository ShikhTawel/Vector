#ifndef CODE_COURSE_H
#define CODE_COURSE_H

#include <bits/stdc++.h>
using namespace std;

class Course
{
private:
    string courseName;
    string courseCode;
    char courseGrade;
    float coursePoint;
    int courseYear;
    int courseSemester;
public:
    Course(): courseName("OOP"),courseCode("1"),courseGrade('A'),coursePoint(4.0),courseYear(19),courseSemester(1) {} //Default Constructor
    Course(string cn,string cc,char cg,float cp,int cy,int cs)      //Constructor With Parameters
    {
        courseName=cn;
        courseCode=cc;
        courseGrade=cg;
        coursePoint=cp;
        courseYear=cy;
        courseSemester=cs;
    }
    friend istream& operator>>(istream& in,Course &s);              //Operator >> Override
    friend ostream& operator<<(ostream& out,Course &s);
    const void printCourseInfo()                                    //Printing the info of the Courses
    {
        cout<<"Course Name: "<<courseName<<"\n";
        cout<<"Course Code: "<<courseCode<<"\n";
        cout<<"Course Grade: "<<courseGrade<<"\n";
        cout<<"Course Point: "<<coursePoint<<"\n";
        cout<<"Course Year: "<<courseYear<<"\n";
        cout<<"Course Semester: "<<courseSemester<<"\n";
        cout<<"-----------------------------------------------------------------\n";
    }
    //The Following are the Class' Setters and Getters
    void setCourseNm(string nm)
    {
        courseName=nm;
    }
    void setCourseCd(string nm)
    {
        courseCode=nm;
    }
    void setCourseGd(char nm)
    {
        courseGrade=nm;
    }
    void setCoursePnt(float nm)
    {
        coursePoint=nm;
    }
    void setCourseYr(int nm)
    {
        courseYear=nm;
    }
    void setCourseSem(int nm)
    {
        courseSemester=nm;
    }
    string getCourseNm()
    {
        return courseName;
    }
    string getCourseCd()
    {
        return courseCode;
    }
    char getCourseGd()
    {
        return courseGrade;
    }
    float getCoursePnt()
    {
        return coursePoint;
    }
    int getCourseYr()
    {
        return courseYear;
    }
    int getCourseSem()
    {
        return courseSemester;
    }
};

istream& operator>>(istream& in, Course &c)                        //Operator >> Override
{
    cout<<"Course Name: "; in>>c.courseName;
    cout<<"Course Code: "; in>>c.courseCode;
    cout<<"Course Grade: "; in>>c.courseGrade;
    cout<<"Course point: "; in>>c.coursePoint;
    cout<<"Course year: "; in>>c.courseYear;
    cout<<"Course Semester: "; in>>c.courseSemester;
    return in;
}
ostream& operator<<(ostream& out,Course &s) {
    ofstream outFile;
    outFile.open("Courses.txt", ios::trunc);
    outFile<<"Course Name: "<<s.courseName<<"\n";
    outFile<<"Course Grade: "<<s.courseGrade<<"\n";
    outFile<<"Course Point: "<<s.coursePoint<<"\n";
    outFile<<"Course Year: "<<s.courseYear<<"\n";
    outFile<<"Course Semester: "<<s.courseSemester<<"\n";
    outFile<<"---------------------------------------------\n";
    outFile.close();
    return out;
}
#endif //CODE_COURSE_H
