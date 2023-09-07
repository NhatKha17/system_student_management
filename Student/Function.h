#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#pragma pack (push)
#pragma pack (1)
typedef enum {
	Male,
	Female,
	Unknow
}Sex;
typedef enum {
	VeryGood,
	Good,
	Average,
	Week
}Rank;

struct StudentInfo {
	char ID[10]; //Student ID can be a maximum of 10 characters long and unique for every student.
	char Name[25]; //Student Name can be a maximum of 25 characters long
	char Email[30];//Student Email can be a maximum of 30 characters long and unique for every student
	char Phone[11];//Student Phones can be maximum of 10 characters long and unique for every student.
	int Age;//Student age can 0 and <100.
	int NumberofCourse; //Student can register maximum 3 courses 
	float GPA;
	Sex Sex;
	Rank Rank;
};
struct CourseInfo {
	char StudentID[10];//that is ID
	char CourseCode[10];//Code of course can be maximum of 10 characters long and unique for every course
	char CourseName[20];//Name of course can be maximum of 20 characters long
};
#pragma pack (pop)

//global variable
extern int TotalStudent ;
extern int TotalCourse ;
char StudentID[10];
struct StudentInfo Student[100];
struct CourseInfo Course[500];

//void Dataseed();//example data
void Option();//menu
void Account();
void WriteStudentToFile(struct StudentInfo student[], int n);
void ReadStudentFromFile(struct StudentInfo student[]);
void WriteCourseToFile(struct StudentInfo course[], int Totalcourse);
void ReadCourseFromFile(struct StudentInfo course[]);
void AddStudent();//add n student
void GuideUser();//guide for user add student
static int  CheckAlreadyExists(char NewInfo[100], char TypeExists);//check fault when add student
static void PrintStudent(struct StudentInfo A);
void ShowAllStudent();//show all student have GPA from high to low
static void ShowGPAHightoLow();//GPA from High to Low
int  SearchStudent();//searching via ID
void EditStudent();
static void DeleteCourseIndex(int FirstCourseIndex);//use edit Student
static void DeleteStudentIndex(int StudentIDdelete);//use edit Student
void DeleteStudent();
void DeleteAllStudent();
void GobackOrExit();
void ExitProgram();//exit program

