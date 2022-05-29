#include "Source.cpp"

using namespace std;
static void TaskManager()
{
	int choice;
	bool Exitflag = false;
	while (!Exitflag)
	{
		cout << "-------------------------------------------------" << endl;
		cout << "press 1 to record a task" << endl;
		cout << "press 2 to update tasks" << endl;
		cout << "press 3 to display the tasks from the hightest priority to lowest priority" << endl;
		cout << "press 4 to edit the tasks" << endl;
		cout << "press 5 to clear all tasks\n";
		cout << "press 6 to exit the program" << endl;
		cout << "--------------------------------------------" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
		{
			readTask();
			break;
		}
		case 2:
		{
			updateTasks();
			break;
		}
		case 3:
		{
			displayTasks();
			break;
		}
		case 4:
		{
			editTasks();
			break;
		}
		case 5:
		{
			clearTasks();
			break;
		}
		case 6:
		{
			exitApp();
			Exitflag = true;
			break;
		}
		default: break;
		}

	}
}

	int main()
	{
		TaskManager();
		return 0;
	}