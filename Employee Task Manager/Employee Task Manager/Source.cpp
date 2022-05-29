#include <iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<string>
#include <stdlib.h>
#include <windows.h>
#include "Header.h"

using namespace std;


struct compare
{
	inline bool operator()(const EmployeeTaskMng& a, const EmployeeTaskMng& b)
	{
		return a.priorityvalues < b.priorityvalues;
	}
};

static priority_queue<EmployeeTaskMng, vector<EmployeeTaskMng>, compare>pq;
static priority_queue<EmployeeTaskMng, vector<EmployeeTaskMng>, compare>New_pq;

static void readTask(){
	ofstream file;
	EmployeeTaskMng emp;
	file.open("Employee_Task.txt",ios::binary);
	if (file.is_open())
	{
		cout << "please enter the  task's details and it's priority" << endl;
		cout << "----------------------------------" << endl;
		cout << "Enter the title of the task:" << endl;
		cin.ignore();
		getline(cin, emp.Tasktitle);
		cout << "Enter the description of the task:" << endl;
		cin.ignore();
		getline(cin, emp.description);
		cout << "Enter the Assigning date of the task:" << endl;
		cout << "Enter Day: ";
		cin >> emp.ASSIGN.day;
		cout << "Enter Month: ";
		cin >> emp.ASSIGN.month;
		cout << "Enter Year: ";
		cin >> emp.ASSIGN.year;
		cout << "Enter the due date of the task:" << endl;
		cout << "Enter Day: ";
		cin >> emp.EnD.day;
		cout << "Enter Month: ";
		cin >> emp.EnD.month;
		cout << "Enter Year: ";
		cin >> emp.EnD.year;
		cout << "Enter the name of employee that task assigned to:" << endl;
		cin.ignore();
		getline(cin, emp.EMPLOYEE);
		cout << "Enter the priority value of the task(1:10 , meaning 1 least important and most important):" << endl;
		cin >> emp.priorityvalues;
		pq.push(emp);
		file.write((char*)&pq, sizeof pq);
		file.close();
	}
	else
	{
		cout << "Unable to open file";
		file.close();
	}
}

static void updateTasks() {
	system("CLS");
	ifstream file;
	ofstream file1;
	file.open("Employee_Task.txt",ios::binary);
	if (file.is_open())
	{
		file.read((char*)&pq, sizeof pq);
		cout << "Task Title: " << pq.top().Tasktitle << endl;
		cout << "Description: " << pq.top().description << endl;
		cout << "Assigned Date: " << pq.top().ASSIGN.day << "/" << pq.top().ASSIGN.month << "/" << pq.top().ASSIGN.year << endl;
		cout << "Due Date: " << pq.top().EnD.day << "/" << pq.top().EnD.month << "/" << pq.top().EnD.year << endl;
		cout << "Employee Name: " << pq.top().EMPLOYEE << endl;
		cout << "Priority: " << pq.top().priorityvalues << endl << endl;
		pq.pop();
		if (pq.empty())
		{
			cout << "----------ALL TASKS ARE FINISHED----------" << endl;
			cout << "YOU ARE A HARD WORKER AND KEEP GOING FOR THE BEST" << endl;
		}
		file.close();
	}
	else
	{
		cout << "no data is present" << endl;
		file.close();
	}
}

static void displayTasks() {
	system("CLS");
	ifstream file;
	ofstream file1;
	file.open("Employee_Task.txt", ios::binary);
	priority_queue<EmployeeTaskMng, vector<EmployeeTaskMng>, compare> copy_queue = pq;

	if (file.is_open())
	{
		file1.open("Display_Task.txt", ios::binary);
		file.read((char*)&copy_queue, sizeof copy_queue);
		while (!copy_queue.empty())
		{
			cout << "Task Title: " << copy_queue.top().Tasktitle << endl;
			cout << "Description: " << copy_queue.top().description << endl;
			cout << "Assigned Date: " << copy_queue.top().ASSIGN.day << "/" << copy_queue.top().ASSIGN.month << "/" << copy_queue.top().ASSIGN.year << endl;
			cout << "Due Date: " << copy_queue.top().EnD.day << "/" << copy_queue.top().EnD.month << "/" << copy_queue.top().EnD.year << endl;
			cout << "Employee Name: " << copy_queue.top().EMPLOYEE << endl;
			cout << "Priority: " << copy_queue.top().priorityvalues << endl << endl;
			file1.write((char*)&copy_queue, sizeof copy_queue);
			copy_queue.pop();
		}

		file.close();
		file1.close();
		remove("Employee_Task.txt");
		rename("Display_Task.txt", "Employee_Task.txt");
	}
	else
	{
		cout << "Unable to open file";
		file.close();
	}
}

static void editTasks() 
{
	system("CLS");
	int choi = 0;
	int newPriority = 0;
	int index = 0;
	ifstream file;
	fstream file1;
	ofstream file2;
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Employee Edit Data -------------------------------------------" << endl;
	file.open("Employee_Task.txt", ios::binary);
	if (file.is_open())
	{
		file1.open("Modify_Task.txt", ios::binary);
		EmployeeTaskMng empl;
		vector<EmployeeTaskMng> tem;
		while (!pq.empty())
		{
			tem.push_back(pq.top());
			pq.pop();
		}
		cout << "Enter index of task you would like to edit\n";
		cin >> index;
		cout << "To edit task priority press 1\n" << "To edit the whole task press 2\n";
		cin >> choi;
		for (int i = 0; i < tem.size(); i++)
		{
			if (index == i)
			{
				if (choi == 1)
				{
					cout << "New Priority: ";
					cin >> newPriority;
					tem[i].priorityvalues = newPriority;
					New_pq.push(tem[i]);
					file1.write((char*)&New_pq, sizeof New_pq);
				}
				else if (choi == 2)
				{
					EmployeeTaskMng empl;
					cout << "please enter the  task's details and it's priority" << endl;
					cout << "----------------------------------" << endl;
					cout << "Enter the title of the task:" << endl;
					cin.ignore();
					getline(cin, empl.Tasktitle);
					cout << "Enter the description of the task:" << endl;
					cin.ignore();
					getline(cin, empl.description);
					cout << "Enter the Assigning date of the task:" << endl;
					cout << "Enter Day: ";
					cin >> empl.ASSIGN.day;
					cout << "Enter Month: ";
					cin >> empl.ASSIGN.month;
					cout << "Enter Year: ";
					cin >> empl.ASSIGN.year;
					cout << "Enter the due date of the task:" << endl;
					cout << "Enter Day: ";
					cin >> empl.EnD.day;
					cout << "Enter Month: ";
					cin >> empl.EnD.month;
					cout << "Enter Year: ";
					cin >> empl.EnD.year;
					cout << "Enter the name of employee that task assigned to:" << endl;
					cin.ignore();
					getline(cin, empl.EMPLOYEE);
					cout << "Enter the priority value of the task(1:10 , meaning 1 least important and most important):" << endl;
					cin >> empl.priorityvalues;
					tem[i] = empl;
					New_pq.push(tem[i]);
					file1.write((char*)&New_pq, sizeof New_pq);
				}
			}
			else
			{
				file1.write((char*)&New_pq, sizeof New_pq);
			}
			
		}
		file1.close();
		file.close();
		remove("Employee_Task.txt");
		rename("Modify_Task.txt", "Employee_Task.txt");
	}
	else
	{
		cout << "\n\t\t\tNo Data is Present... ";
		file.close();

	}

}


static void clearTasks() 
{

	ifstream file;
	file.open("Employee_Task.txt", ios::binary);
	file.read((char*)&pq, sizeof pq);
	while (!pq.empty())
	{
		pq.pop();
	}
	file.close();
	file.clear();
	cout << "succesifully clear all of the task" << endl;

}


static void exitApp() 
{
	system("CLS");
	ifstream file;
	file.open("Employee_Task.txt", ios::binary);
	file.read((char*)&pq, sizeof pq);
	cout << "\t\t\t\t\tDON'T FORGET THE NEXT TASK TO BE DONE\n\n";
	cout << "Task Title: " << pq.top().Tasktitle << endl;
	cout << "Description: " << pq.top().description << endl;
	cout << "Assigned Date: " << pq.top().ASSIGN.day << "/" << pq.top().ASSIGN.month << "/" << pq.top().ASSIGN.year << endl;
	cout << "Due Date: " << pq.top().EnD.day << "/" << pq.top().EnD.month << "/" << pq.top().EnD.year << endl;
	cout << "Employee Name: " << pq.top().EMPLOYEE << endl;
	cout << "Priority: " << pq.top().priorityvalues << endl;
	file.close();
	Sleep(4000);
}

/*

	cout << "Enter index of task you would like to edit\n";
		cin >> index;
		cout << "To edit task priority press 1\n" << "To edit the whole task press 2\n";
		cin >> choice2;

		if (choice2 == 1)
		{
			cout << "New Priority: ";
			cin >> newPriority;
			pq[index - 1].priorityvalues = newPriority;
			sort(pq.begin(), pq.end(), compare());
			file1.write((char*)&pq, sizeof pq);
		}
		else if (choice2 == 2)
		{
			EmployeeTaskMng empl;
			cout << "please enter the  task's details and it's priority" << endl;
			cout << "----------------------------------" << endl;
			cout << "Enter the title of the task:" << endl;
			cin.ignore();
			getline(cin, empl.Tasktitle);
			cout << "Enter the description of the task:" << endl;
			cin.ignore();
			getline(cin, empl.description);
			cout << "Enter the Assigning date of the task:" << endl;
			cout << "Enter Day: ";
			cin >> empl.ASSIGN.day;
			cout << "Enter Month: ";
			cin >> empl.ASSIGN.month;
			cout << "Enter Year: ";
			cin >> empl.ASSIGN.year;
			cout << "Enter the due date of the task:" << endl;
			cout << "Enter Day: ";
			cin >> empl.EnD.day;
			cout << "Enter Month: ";
			cin >> empl.EnD.month;
			cout << "Enter Year: ";
			cin >> empl.EnD.year;
			cout << "Enter the name of employee that task assigned to:" << endl;
			cin.ignore();
			getline(cin, empl.EMPLOYEE);
			cout << "Enter the priority value of the task(1:10 , meaning 1 least important and most important):" << endl;
			cin >> empl.priorityvalues;
			pq[index - 1] = empl;
			sort(pq.begin(), pq.end(), compare());
			file1.write((char*)&pq, sizeof pq);
		}*/