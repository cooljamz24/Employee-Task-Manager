#pragma once
#include<string>
using namespace std;

struct date
{
	int day;
	int month;
	int year;
};
class EmployeeTaskMng
{
public:

	string Tasktitle;
	string description;
	date ASSIGN;
	date EnD;
	string EMPLOYEE;
	int priorityvalues;
};
