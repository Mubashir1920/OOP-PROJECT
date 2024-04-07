#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <windows.h>
using namespace std;

void Loading()
{
	int i = 0;
	cout << "\n\t\t\tLoading....\n\t\t\t";
	for (i = 0; i <= 50; i++)
	{
		cout << char(219);
		if (i < 20)
		{
			Sleep(40);
		}
		else if (i < 50)
		{
			Sleep(25);
		}
	}
}

void showallcars(string Loginid)
{
	int count = 0;
	string id;
	ifstream file;
	string data;
	string userid;

	file.open("sellers.csv");
	Loading();

	while (getline(file, data))
	{
		istringstream iss(data);
		getline(iss, userid, ',');
		if (userid == Loginid)
		{
			cout << endl;
			string name, numberplate, model, make, company, colour, condition, enginecapacity, status;
			getline(iss, numberplate, ',');
			getline(iss, model, ',');
			getline(iss, make, ',');
			getline(iss, company, ',');
			getline(iss, colour, ',');
			getline(iss, condition, ',');
			getline(iss, enginecapacity, ',');
			getline(iss, status, '\n');
			cout << "Model: " << model << endl;
			cout << "Numberplate: " << numberplate << endl;
			cout << "Company: " << company << endl;
			cout << "Colour: " << colour << endl;
			cout << "Conditon: " << condition << endl;
			cout << "Engine capacity: " << enginecapacity << endl;
			cout << "Status: " << status << endl;
			cout << "____________________________________________________" << endl;
			cout << "----------------------------------------------------" << endl;
			count++;
			Sleep(800);
		}
	}
	if (count == 0)
	{
		int i = 0;
		cout << endl;
		cout << "There is no record against"
			 << " " << Loginid << " "
			 << "in our system" << endl;
	}
	file.close();
}

int main()
{
	string i;
	cout << "enter id" << endl;
	cin >> i;
	showallcars(i);
	return 0;
}
